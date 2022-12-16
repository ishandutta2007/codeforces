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

#define MAXN 100'010

constexpr ll mod = 1e9 + 7;

int par[MAXN];
bool spec[MAXN];
int getPar(int x) {
    if (par[x] == x) return x;
    return par[x] = getPar(par[x]);
}

void Union(int x, int y) {
    if (getPar(x) == getPar(y)) return;

    if (spec[getPar(x)]) spec[getPar(y)] = true;
    par[getPar(x)] = getPar(y);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            par[i] = i;
            spec[i] = false;
        }

        int a[n];
        int b[n];
        int c[n];
        rep(i, 0, n) {
            cin >> a[i]; a[i]--;
        }
        rep(i, 0, n) {
            cin >> b[i]; b[i]--;
        }
        rep(i, 0, n) {
            cin >> c[i]; c[i]--;
        }

        rep(i, 0, n) {
            Union(a[i], b[i]);
            if (a[i] == b[i] || c[i] != -1) {
                //cout << "setting " << i << endl;
                spec[getPar(a[i])] = true;
            }
        }

        set<int> nonspec;
        rep(i, 0, n) {
            //cout << i << ' ' << getPar(i) << ' ' << spec[getPar(i)] << endl;
            if (!spec[getPar(i)]) {
                nonspec.insert(getPar(i));
            }
        }

        ll out = 1;
        rep(i, 0, sz(nonspec)) {
            out *= 2;
            out %= mod;
        }
        cout << out << '\n';
    }
}