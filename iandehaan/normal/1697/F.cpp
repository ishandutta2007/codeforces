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

struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int addVar() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void setValue(int x) { either(x, x); }

	void atMostOne(const vi& li) { // (optional)
		if (sz(li) <= 1) return;
		int cur = ~li[0];
		rep(i,2,sz(li)) {
			int next = addVar();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

int k;
int getId(int varnum, int val) {
    // varnum >= val
    return k*varnum + val-1;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m >> k;

        TwoSat ts(n*k);
        // [0, ..., k) x0 >= 1, x0 >= 2, ..., x0 >= k
        // [k*i, ..., k*(i+1)) xi >= 1, xi >= 2, ..., xi >= k

        rep(i, 0, n) {
            rep(j, 2, k+1) {
                // x >= j implies x >= j-1
                ts.either(~getId(i, j), getId(i, j-1));

                // xi >= j implies x(i+1) >= j
                if (i != n-1) {
                    ts.either(~getId(i, j), getId(i+1, j));
                }
            }
            ts.setValue(getId(i, 1));
        }
       

        //cerr << "here" << endl;

        for (int i = 0; i < m; i++) {
            //cerr << i << endl;
            int cmd;
            cin >> cmd;
            //cerr << cmd << endl;
            if (cmd == 1) {
                int ind, x;
                cin >> ind >> x;
                ind--;
                // ind >= x + 1 or (not ind >= x)
                if (x != k) ts.either(getId(ind, x+1), ~getId(ind, x));
                else ts.setValue(~getId(ind, x));
            } else if (cmd == 2) {
                int ind1, ind2, x;
                cin >> ind1 >> ind2 >> x;
                ind1--;
                ind2--;

                rep(j, 1, k+1) {
                    // ind1 >= j implies (not ind2 >= x-j + 1)

                    if (j >= x) {
                        // don't let ind1 >= j
                        ts.setValue(~getId(ind1, j));
                        ts.setValue(~getId(ind2, j));
                    } else if (x-j+1 <= k) {
                        ts.either(~getId(ind1, j), ~getId(ind2, x-j+1));
                        ts.either(~getId(ind2, j), ~getId(ind1, x-j+1));
                    }
                }
            } else if (cmd == 3) {
                //cerr << "what" << endl;
                int ind1, ind2, x;
                cin >> ind1 >> ind2 >> x;
                ind1--;
                ind2--;
                //cerr << ind1 << ' ' << ind2 << ' ' << x << endl;
                rep(j, 1, k) {
                    // (not ind1 >= j+1) implies ind2 >= x - j

                    if (x-j > k) {
                        // don't let ind1 <= j
                        ts.setValue(getId(ind1, j+1));
                        ts.setValue(getId(ind1, j+1));
                    } else if (x-j >= 1) {
                        ts.either(getId(ind1, j+1), getId(ind2, x-j));
                        ts.either(getId(ind2, j+1), getId(ind1, x-j));
                    }
                }
            }
        }

        //cerr << "here2" << endl;

        if (ts.solve()) {
            int out[n];
            rep(i, 0, n) {
                for (int j = k; j >= 1; j--) {
                    if (ts.values[getId(i, j)]) {
                        //cout << i+1 << " >= " << j << ' ' << "works" << endl;
                        out[i] = j;
                        break;
                    }
                }
                /*for (int j = k; j >= 1; j--) {
                    int xgeqj =  n*k + k*i + (j-1);
                    if (ts.values[xgeqj]) {
                        cout << i+1 << " <= " << j << ' ' << "works" << endl;
                        out[i] = j;
                        //break;
                    }
                }*/
            }

            rep(i, 0, n) cout << out[i] << ' ';
            cout << endl;

        } else {
            cout << -1 << endl;
        }
    }
}