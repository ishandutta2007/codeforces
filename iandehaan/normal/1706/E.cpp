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

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

int par[MAXN];
set<pii> unmatched[MAXN];
vector<int> vals;

int getPar(int x) {
    if (par[x] == x) return x;
    return par[x] = getPar(par[x]);
}

void Union(int x, int y, int ind) {
    int parx = getPar(x);
    int pary = getPar(y);
    if (parx == pary) return;
    if (sz(unmatched[pary]) > sz(unmatched[parx])) swap(parx, pary);

    // merge pary into parx

    for (pii val : unmatched[pary]) {
        if (unmatched[parx].count(val) != 0) {
            vals[val.first] = -1*ind;

            unmatched[parx].erase(val);
        } else {
            unmatched[parx].insert(val);
        }
    }


    par[pary] = parx;
}


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        vals.resize(n-1);
        rep(i, 0, n) {
            par[i] = i;
            unmatched[i].clear();
            unmatched[i].insert(mp(i-1, i));
            if (i != n-1) unmatched[i].insert(mp(i, i+1));
        }

        rep(i, 0, m) {
            int u, v;
            cin >> u >> v;
            u--; v--;

            Union(u, v, i+1);
        }

        RMQ rt(vals);

        while (q--) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            if (u == v) {
                cout << 0 << ' ';
                continue;
            }

            cout << -1*rt.query(u, v) << ' ';
        }
        cout << '\n';
    }
}