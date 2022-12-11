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

struct SuffixAutomaton {

	SuffixAutomaton(const string& s) {
		t.pb(node());
		last = 0;
		for (int i = 0; i < sz(s); ++i) {
			add(s[i]);
		}

		vector<int> order;
	    for (int v = 0; v < sz(t); ++v) {
	    	order.pb(v);
	    }
	 
	    sort(all(order), [&] (int u, int v) { return t[u].len < t[v].len; });
	    reverse(all(order));
	 
	    int tmp = order[0];
	    ++t[tmp].num;
	    ++t[tmp].sum;
	    while (true) {
	    	tmp = t[tmp].link;
	    	if (tmp == -1) {
	    		break;
	    	}
	    	++t[tmp].num;
	    	++t[tmp].sum;
	    }
	 
	    for (int v : order) {
	    	for (auto it : t[v].to) {
	    		t[v].num += t[it.second].num;
	    	}
	    }

	    for (int v : order) {
	    	for (auto it : t[v].to) {
	    		t[v].sum += t[it.second].sum + t[it.second].num;
	    	}
	    }
	}

	struct node {
		int link;
		int len;
		map<char, int> to;
		int num; // right-context size
		ll sum;
		int firstpos;
		int lastpos;
		node() : link(-1), len(0), num(0), sum(0) {}
	};
 
	vector<node> t;
	int last;
	 
	void add(char c) {
		int curr = sz(t);
		t.pb(node());
		t[curr].len = t[last].len + 1;
		t[curr].firstpos = t[curr].lastpos = t[last].len;
		int p = last;
		while (p != -1 && !t[p].to.count(c)) {
			t[p].to[c] = curr;
			p = t[p].link;
		}
		if (p == -1) {
			t[curr].link = 0;
			last = curr;
			return;
		}
		int q = t[p].to[c];
		if (t[q].len == t[p].len + 1) {
			t[curr].link = q;
			last = curr;
			return;
		}
		int clone = sz(t);
		t.pb(node());
		t[clone].len = t[p].len + 1;
		t[clone].firstpos = t[q].firstpos;
		t[q].lastpos = t[last].len;
		t[clone].link = t[q].link;
		t[clone].to = t[q].to;
		t[curr].link = clone;
		t[q].link = clone;
		last = curr;
		while (p != -1 && t[p].to[c] == q) {
			t[p].to[c] = clone;
			p = t[p].link;
		}
	}

};

const int rmax = 23;
const int nmax = 500500;

vector<vector<int> > sparse;
int deg[nmax];

int getMin(int l, int r) {
	int k = deg[r - l + 1];
	return min(sparse[k][l], sparse[k][r - (1 << k) + 1]);
}

struct query {
	int l, r;
	int x;
	bool operator<(const query& other) const {
		return x < other.x;
	}
};

vector<int> t;
int N;

void revive(int v, int tl, int tr, int pos) {
	++t[v];
	if (tl == tr) {
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm) {
		revive(v * 2, tl, tm, pos);
	} else {
		revive(v * 2 + 1, tm + 1, tr, pos);
	}
}

int getSum(int v, int tl, int tr, int l, int r) {
	if (tl == l && tr == r) {
		return t[v];
	}
	int ans = 0;
	int tm = (tl + tr) >> 1;
	if (l <= tm) {
		ans += getSum(v * 2, tl, tm, l, min(r, tm));
	}
	if (r > tm) {
		ans += getSum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	}
	return ans;
}

int kth(int v, int tl, int tr, int k) {
	if (k + t[v] > tr - tl + 1) {
		return -1;
	}
	if (tl == tr) {
		return tl;
	}
	int tm = (tl + tr) >> 1;
	if (k + t[v * 2 + 1] <= tr - tm) {
		return kth(v * 2 + 1, tm + 1, tr, k);
	} else {
		k -= (tr - tm) - t[v * 2 + 1];
		//cout << "LOL " << k << " " << t[v] << " " << t[v * 2] << " " << t[v * 2 + 1] << endl;
		return kth(v * 2, tl, tm, k);
	}
}

int getCount(const vector<int>& a, int l, int r) {
	int i = lower_bound(all(a), l) - a.begin();
	int j = upper_bound(all(a), r) - a.begin() - 1;
	return max(0, j - i + 1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> suff(n + 1);
    vector<char> good(n + 1);
    int maxx = 0;
    suff[n] = 0;
    good[n] = true;

    for (int i = n - 1; i >= 0; --i) {
    	suff[i] = suff[i + 1];
    	if (s[i] == '(') {
    		++suff[i];
    	} else {
    		--suff[i];
    	}
    	if (suff[i] < maxx) {
    		good[i] = false;
    	} else {
    		good[i] = true;
    	}
    	maxx = max(maxx, suff[i]);
    }

    vector<int> pref(n);
    for (int i = 0; i < n; ++i) {
    	if (i) {
    		pref[i] = pref[i - 1];
    	}
    	if (s[i] == '(') {
    		++pref[i];
    	} else {
    		--pref[i];
    	}
    }

    sparse = vector<vector<int> >(rmax, vector<int>(nmax));
    for (int i = 0; i < n; ++i) {
    	sparse[0][i] = pref[i];
    }
    for (int r = 0; r + 1 < rmax; ++r) {
    	for (int i = 0; i < n; ++i) {
    		int j = min(n - 1, i + (1 << r));
    		sparse[r + 1][i] = min(sparse[r][i], sparse[r][j]);
    	}
    }

    deg[1] = 0;
    for (int i = 2; i < nmax; ++i) {
    	deg[i] = deg[i - 1];
    	if (!(i & (i - 1))) {
    		++deg[i];
    	}
    }

    SuffixAutomaton sa(s);

    ll ans = 0;

    vector<query> queries;

    for (int v = 1; v < sz(sa.t); ++v) {
    	int p = sa.t[v].link;
    	int i = sa.t[v].firstpos - sa.t[v].len + 1;
    	if (p == 0) {
    		queries.pb({i, sa.t[v].firstpos, suff[sa.t[v].firstpos + 1]});
    		continue;
    	}
    	
    	int l = i + (sa.t[v].len - sa.t[p].len);
    	int r = l + sa.t[p].len - 1;
    	int bal =  suff[l] - suff[r + 1];
    	int minn = getMin(l, r);
    	if (l) {
    		minn -= pref[l - 1];
    	}
    	if (bal > 0 || minn < bal) {
    		continue;
    	}
    	int b = suff[r + 1];
    	queries.pb({i, l - 1, b});
    	//cout << "!" << i << " " << l - 1 << " " << b << " (from " << l << " " << r << ")" << endl;
    }

    sort(all(queries));

    /*for (int i = 0; i < sz(queries); ++i) {
    	cout << queries[i].l << " " << queries[i].r << " " << queries[i].x << endl;
    }*/

    N = n + 1;
    t.assign(4 * N, 0);

    vector<int> vct;
    for (int i = 0; i <= n; ++i) {
    	vct.pb(i);
    }
    sort(all(vct), [&] (int a, int b) { return (suff[a] < suff[b]) || (suff[a] == suff[b] && a < b); });

    int ptr = 0;
    int i = 0, j = 0;

    while (i < sz(queries)) {
    	int x = queries[i].x;
    	while (j < sz(vct) && suff[vct[j]] < x) {
    		//cout << "revive " << vct[j] << endl;
    		revive(1, 0, N - 1, vct[j]);
    		++j;
    	}
    	if (j >= sz(vct) || suff[vct[j]] > x) {
    		++i;
    		continue;
    	}
    	vector<int> curr;
    	while (j < sz(vct) && suff[vct[j]] == x) {
    		//cout << "revive " << vct[j] << endl;
    		revive(1, 0, N - 1, vct[j]);
    		curr.pb(vct[j]);
    		++j;
    	}
    	while (i < sz(queries) && queries[i].x == x) {
    		int l = queries[i].l, r = queries[i].r;
    		//cout << "!" << l << " " << r << " " << x << " " << getSum(1, 0, N - 1, r + 1, N - 1) << endl;
    		int k = (N - 1) - (r + 1) + 1 - getSum(1, 0, N - 1, r + 1, N - 1);
    		++k;
    		int pos = max(kth(1, 0, N - 1, k), l);
    		//cout << k << " " << kth(1, 0, N - 1, k) << endl;
    		ans += getCount(curr, pos, r);
    		//cout << "!" << ans << endl;
    		++i;
    	}
    }

    cout << ans << "\n";

}