#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

struct SuffixArray {

	SuffixArray(const vector<int>& s) : s(s) {
		p.resize(nmax);
		c.resize(nmax);
		cnt.assign(nmax, 0);
		pn.resize(nmax);
		cn.resize(nmax);
		lcp.resize(nmax);
		pos.resize(nmax);
		deg.resize(nmax);
		sparse = vector<vector<int> >(rmax, vector<int>(nmax));
	    n = sz(s);
	    for (int i = 0; i < sz(s); ++i) {
	        ++cnt[s[i]];
	    }
	    for (int i = 1; i < sigma; ++i) {
	        cnt[i] += cnt[i - 1];
	    }
	    for (int i = n - 1; i >= 0; --i) {
	        p[--cnt[s[i]]] = i;
	    }
	    c[p[0]] = 0;
	    int curr = 0;
	    for (int i = 1; i < n; ++i) {
	        if (s[p[i]] != s[p[i - 1]]) {
	            ++curr;
	        }
	        c[p[i]] = curr;
	    }
	    ++curr;
	    int len = 2;
	    while (true) {
	        for (int i = 0; i < n; ++i) {
	            pn[i] = p[i] - (len >> 1);
	            if (pn[i] < 0) {
	                pn[i] += n;
	            }
	        }
	        cnt.assign(curr, 0);
	        for (int i = 0; i < n; ++i) {
	            ++cnt[c[i]];
	        }
	        for (int i = 1; i < curr; ++i) {
	            cnt[i] += cnt[i - 1];
	        }
	        for (int i = n - 1; i >= 0; --i) {
	            p[--cnt[c[pn[i]]]] = pn[i];
	        }
	        cn[p[0]] = 0;
	        curr = 0;
	        for (int i = 1; i < n; ++i) {
	            if (c[p[i]] != c[p[i - 1]]) {
	                ++curr;
	            } else {
	                int x = p[i] + (len >> 1), y = p[i - 1] + (len >> 1);
	                if (x >= n) {
	                    x -= n;
	                }
	                if (y >= n) {
	                    y -= n;
	                }
	                if (c[x] != c[y]) {
	                    ++curr;
	                }
	            }
	            cn[p[i]] = curr;
	        }
	        ++curr;
	        c = cn;
	        if (len >= n) {
	            break;
	        }
	        len <<= 1;
	    }

	    deg[1] = 0;
	    for (int i = 2; i < nmax; ++i) {
	        deg[i] = deg[i - 1];
	        if (!(i & (i - 1))) {
	            ++deg[i];
	        }
	    }

	    for (int i = 0; i < n; ++i) {
	        pos[p[i]] = i;
	    }

	    curr = 0;
	    for (int i = 0; i < n; ++i) {
	        curr = max(curr - 1, 0);
	        if (pos[i] + 1 == n) {
	            curr = 0;
	            continue;
	        }
	        int j = p[pos[i] + 1];
	        while (i + curr < n && j + curr < n && s[i + curr] == s[j + curr]) {
	            ++curr;
	        }
	        lcp[pos[i]] = curr;
	    }

	    for (int i = 0; i < n; ++i) {
	        sparse[0][i] = lcp[i];
	    }
	    for (int r = 0; r + 1 < rmax; ++r) {
	        for (int i = 0; i < n; ++i) {
	            int j = min(n - 1, i + (1 << r));
	            sparse[r + 1][i] = min(sparse[r][i], sparse[r][j]);
	        }
	    }
	}

	int get(int l, int r) {
	    int len = r - l + 1;
	    int k = deg[len];
	    return min(sparse[k][l], sparse[k][l + len - (1 << k)]);
	}

	vector<int> s;
	int n;

	static const int nmax = 200500;
	static const int rmax = 20;
	static const int sigma = 200500;
	
	vector<int> p, c, cnt, pn, cn, lcp, pos, deg;
	vector<vector<int> > sparse;
};

struct query {
	int lf, rg;
	int x;
	int id;
	string sgn;
	bool operator<(const query& other) {
		if (sgn == "<=") {
			return x < other.x;
		} else {
			return x > other.x;
		}
	}
};

struct SegmentTree {

	SegmentTree(int n) : n(n) {
		t.assign(2 * n, 0);
	}

	void revive(int pos) {
		for (pos += n; pos; pos >>= 1) {
			++t[pos];
		}
	}

	int get(int l, int r) {
		int ans = 0;
		for (l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
			if (l & 1) {
				ans += t[l];
			}
			if (!(r & 1)) {
				ans += t[r];
			}
		}
		return ans;
	}

	vector<int> t;
	int n;
};
 
int main() {

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }

    vector<int> d;
    vector<int> diffs;
    for (int i = 1; i < n; ++i) {
    	diffs.pb(a[i] - a[i - 1]);
    	diffs.pb(a[i - 1] - a[i]);
    }
    sort(all(diffs));
    diffs.resize(unique(all(diffs)) - diffs.begin());

    for (int i = 1; i < n; ++i) {
    	int val = a[i] - a[i - 1];
    	d.pb(lower_bound(all(diffs), val) - diffs.begin() + 2);
    }
    d.pb(0);
    for (int i = 1; i < n; ++i) {
    	int val = a[i - 1] - a[i];
    	d.pb(lower_bound(all(diffs), val) - diffs.begin() + 2);
    }
    d.pb(1);

    SuffixArray array(d);
    int q;
    cin >> q;
    vector<int> ans(q);

    vector<query> leq;
    vector<query> geq;

    /*for (int i = 0; i < sz(d); ++i) {
    	cout << array.p[i] << " ";
    }
    cout << "\n";*/

    for (int i = 0; i < q; ++i) {
    	int l, r;
    	cin >> l >> r;
    	--l, --r;
    	if (l == r) {
    		ans[i] = n - 1;
    		continue;
    	}
    	int pos = array.pos[l];
    	int lf = pos, rg = sz(d);
    	while (rg - lf > 1) {
    		int md = (lf + rg) >> 1;
    		assert(md != pos);
    		int x = array.get(pos, md - 1);
    		if (x >= r - l) {
    			lf = md;
    		} else {
    			rg = md;
    		}
    	}
    	int y = lf;
    	lf = -1, rg = pos;
    	while (rg - lf > 1) {
    		int md = (lf + rg) >> 1;
    		assert(md != pos);
    		int x = array.get(md, pos - 1);
    		if (x >= r - l) {
    			rg = md;
    		} else {
    			lf = md;
    		}
    	}
    	int x = rg;
    	//cout << i << " " << x << " " << y << endl;
    	assert(x == y || array.get(x, y - 1) >= r - l);
    	assert(x == 0 || array.get(x - 1, y) < r - l);
    	assert(y == sz(d) - 1 || array.get(x, y) < r - l);
    	//cout << x << " " << y << endl;
    	//cout << x << " " << y << endl;
    	leq.pb({x, y, l - (r - l + 1), i, "<="}); // <= 
    	geq.pb({x, y, r + 1, i, ">="}); // >=
    }

    sort(all(leq));
    SegmentTree segtree(2 * n);
    int prev = -1;

    for (query& qu : leq) {
    	//cout << qu.x << endl;
    	for (int j = prev + 1; j <= qu.x; ++j) {
    		segtree.revive(array.pos[j + n]);
    	}
    	prev = max(prev, qu.x);
    	ans[qu.id] += segtree.get(qu.lf, qu.rg);
    }

    segtree = SegmentTree(2 * n);
    prev = n;
    sort(all(geq));

    for (query& qu : geq) {
    	for (int j = prev - 1; j >= qu.x; --j) {
    		segtree.revive(array.pos[j + n]);
    	}
    	prev = min(prev, qu.x);
    	ans[qu.id] += segtree.get(qu.lf, qu.rg);
    }

    for (int i = 0; i < q; ++i) {
    	cout << ans[i] << "\n";
    }
 
}