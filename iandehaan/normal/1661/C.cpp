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
#define MAXN 300'010
int n;
int a[MAXN];


bool works(ll numone, ll numtwo) {
    if (numone < 0) return false;

    for (int i = 0; i < n; i++) {
        int diff = a[n-1] - a[i];

        int numposstwo = diff / 2;
        if (numposstwo > numtwo) {
            diff -= 2*numtwo;
            numtwo = 0;
        } else {
            diff -= 2*numposstwo;
            numtwo -= numposstwo;
        }

        numone -= diff;
    }
    //cout << numone << ' ' << numtwo << endl;
    if (numone < 0) return false;
    return true;
}

ll binSearch(bool special) {
    ll hi = ((ll) 1) << ((ll) 50);
    ll lo = 0;

    while (abs(hi-lo) > 2) {
        ll mid = (lo+hi)/2;

        ll numones = (mid + 1) / 2;
        ll numtwos = mid / 2;
        if (special) numones--;
        if (works(numones, numtwos)) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }

    for (ll i = lo; i <= hi; i++) {
        ll numones = (i + 1) / 2;
        ll numtwos = i / 2;
        if (special) numones--;
        if (works(numones, numtwos)) return i; 
    }
    return hi+1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n);

        //cout << works(2, 2) << endl;

        ll out = binSearch(false);
        a[n-1]++;
        out = min(out, binSearch(true));
        cout << out << '\n';
    }
}