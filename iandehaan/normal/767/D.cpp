#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

#define MAXN 1'000'010
ll n, m, k;
vector<int> a;
pair<int, int> b[MAXN];

bool works(int amt) {
    int ptr1 = 0;
    int ptr2 = m - amt;

    for (int i = 0; i < n + amt; i++) {
        int val = 0;
        if (ptr1 == n || (ptr2 != m && a[ptr1] > b[ptr2].first)) {
            // use b
            val = b[ptr2].first;
            ptr2++;
        } else {
            val = a[ptr1];
            ptr1++;
        }
        if ((val+1)*k < (i+1)) {
            //cout << i << ' ' << used[i] << ' ' << amt << endl;
            return false;
        }
    }
    return true;
}

void printOut(int amt) {
    //vector<int> usedind;
    for (int i = m - amt; i < m; i++) {
        cout << b[i].second << ' ';
    }
    cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;

    a.resize(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        cin >> b[i].first;
        b[i].second = i+1;
    }
    sort(all(a));
    sort(b, b+m);

    int hi = m;
    int lo = 0;
    while (abs(hi-lo) > 2) {
        int mid = (hi+lo)/2;

        if (works(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    int out = -1;
    for (int i = hi; i >= lo; i--) {
        if (works(i)) {
            out = i;
            break;
        }
    }
    cout << out << endl;
    if (out > 0) printOut(out);
}