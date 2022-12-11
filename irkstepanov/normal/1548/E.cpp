#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

struct ST {
	int n;
	vector<int> t;

	ST() {}

	ST(int n) : n(n) {
		t.assign(2 * n, 0);
	}

	void update(int pos, int val) {
		for (pos += n; pos; pos >>= 1) {
			t[pos] += val;
		}
	}

	int get(int l, int r) {
		if (l < 0) {
			l = 0;
		}
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
};

const int nmax = 200500;
const int rmax = 20;

struct SparseTableMax {
	int n;
	vector<vector<int> > sparse;
	vector<int> degs;

	SparseTableMax() {}
	SparseTableMax(vector<int>& a) : n(sz(a)) {
		sparse = vector<vector<int> >(rmax, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			sparse[0][i] = a[i];
		}
		for (int r = 0; r + 1 < rmax; ++r) {
			for (int i = 0; i < n; ++i) {
				int j = min(n - 1, i + (1 << r));
				sparse[r + 1][i] = max(sparse[r][i], sparse[r][j]);
			}
		}
		degs.resize(n + 1);
		degs[1] = 0;
		for (int i = 2; i <= n; ++i) {
			degs[i] = degs[i - 1];
			if (!(i & (i - 1))) {
				++degs[i];
			}
		}
	}

	int get(int l, int r) {
		int k = degs[r - l + 1];
		return max(sparse[k][l], sparse[k][r - (1 << k) + 1]);
	}

};

struct SparseTableMin {
	int n;
	vector<vector<int> > sparse;
	vector<int> degs;

	SparseTableMin() {}
	SparseTableMin(vector<int>& a) : n(sz(a)) {
		sparse = vector<vector<int> >(rmax, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			sparse[0][i] = a[i];
		}
		for (int r = 0; r + 1 < rmax; ++r) {
			for (int i = 0; i < n; ++i) {
				int j = min(n - 1, i + (1 << r));
				sparse[r + 1][i] = min(sparse[r][i], sparse[r][j]);
			}
		}
		degs.resize(n + 1);
		degs[1] = 0;
		for (int i = 2; i <= n; ++i) {
			degs[i] = degs[i - 1];
			if (!(i & (i - 1))) {
				++degs[i];
			}
		}
	}

	int get(int l, int r) {
		int k = degs[r - l + 1];
		return min(sparse[k][l], sparse[k][r - (1 << k) + 1]);
	}

};

set<pii> segs;
ST st_for_sergs;

void add_min(int b) {
	st_for_sergs.update(b, 1);
}

void del_min(int b) {
	st_for_sergs.update(b, -1);
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n, m, x;
    cin >> n >> m >> x;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
    	cin >> b[i];
    }

    vector<pii> sorted_a;
    for (int i = 0; i < n; ++i) {
    	sorted_a.pb({a[i], i});
    }
    sort(all(sorted_a));

    vector<pii> sorted_b;
    for (int i = 0; i < m; ++i) {
    	sorted_b.pb({b[i], i});
    }
    sort(all(sorted_b));

    int i0 = sorted_a[0].second;
    st_for_sergs = ST(nmax);
    int curr_l = -1, curr_r = -1;
    int curr_opt = -1;
    for (int j = 0; j <= m; ++j) {
    	if (j < m && a[i0] + b[j] <= x) {
    		if (curr_l == -1) {
    			curr_l = curr_r = curr_opt = j;
    		} else {
    			++curr_r;
    			if (b[j] < b[curr_opt]) {
    				curr_opt = j;
    			}
    		}
    	} else if (curr_l != -1) {
    		segs.insert({curr_l, curr_r});
    		curr_l = -1, curr_r = -1;
    		add_min(b[curr_opt]);
    		curr_opt = -1;
    	}
    }

    int ptr = -1;
    for (int i = 0; i < m; ++i) {
    	if (sorted_b[i].first + a[i0] <= x) {
    		ptr = i;
    	}
    }

    vector<int> nx(n, -1);
    nx[n - 1] = -1;
    for (int i = n - 2; i >= 0; --i) {
    	if (a[i + 1] < a[i]) {
    		nx[i] = i + 1;
    		continue;
    	}
    	int curr = i + 1;
    	while (curr != -1 && a[curr] >= a[i]) {
    		curr = nx[curr];
    	}
    	nx[i] = curr;
    }

    vector<int> prev(n, -1);
    prev[0] = -1;
    for (int i = 1; i < n; ++i) {
    	if (a[i - 1] <= a[i]) {
    		prev[i] = i - 1;
    		continue;
    	}
    	int curr = i - 1;
    	while (curr != -1 && a[curr] > a[i]) {
    		curr = prev[curr];
    	}
    	prev[i] = curr;
    }

    SparseTableMax ST_for_a(a);
    SparseTableMin ST_for_b(b);

    ll ans = sz(segs);
    for (int step = 1; step < n; ++step) {
    	int i = sorted_a[step].second;
    	while (ptr >= 0 && sorted_b[ptr].first + a[i] > x) {
    		int j = sorted_b[ptr].second;
    		set<pii>::iterator it = segs.lower_bound({j + 1, j + 1});
    		--it;
    		int l = it->first, r = it->second;
    		del_min(ST_for_b.get(l, r));
    		segs.erase(it);
    		if (l < j) {
    			add_min(ST_for_b.get(l, j - 1));
    			segs.insert({l, j - 1});
    		}
    		if (j < r) {
    			add_min(ST_for_b.get(j + 1, r));
    			segs.insert({j + 1, r});
    		}
    		--ptr;
    	}
    	if (ptr == -1) {
    		break;
    	}
    	int maxx = nmax;
    	if (prev[i] != -1) {
    		maxx = min(maxx, ST_for_a.get(prev[i], i));
    	}
    	if (nx[i] != -1) {
    		maxx = min(maxx, ST_for_a.get(i, nx[i]));
    	}
    	ans += st_for_sergs.get(x - maxx + 1, nmax - 1);
    }

    cout << ans << "\n";

}