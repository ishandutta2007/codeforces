#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;

const int nmax = 1e6 + 100;

int t[2 * nmax];
int n;

int get(int l, int r) {
    int ans = 0;
    for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
        if (l & 1) {
            ans = max(ans, t[l]);
        }
        if (!(r & 1)) {
            ans = max(ans, t[r]);
        }
    }
    return ans;
}

void upd(int pos, int val) {
    for (pos += n; pos; pos >>= 1) {
        t[pos] = max(t[pos], val);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    cin >> n;

    vector<int> a(n), b(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        r[b[i] - 1] = i;
    }

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        int x = a[i] - 1;
        p[i] = r[x];
    }

    for (int i = 0; i < n; ++i) {
        int x = p[i];
        int val = get(x + 1, n - 1);
        //cout << x << " " << val << endl;
        upd(x, val + 1);
    }

    cout << get(0, n - 1) << "\n";

}