#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

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

vector<int> p_func(const string& s) {
	int n = sz(s);
	vector<int> p(n);
	for (int i = 1; i < n; ++i) {
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = p[j - 1];
		}
		if (s[i] == s[j]) {
			++j;
		}
		p[i] = j;
	}
	return p;
}

int main() {

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    SuffixAutomaton automaton(s);

    vector<int> p = p_func(s);
    vector<int> cnt(sz(s) + 1);
    int v = 0;
    for (int i = 0; i < sz(s); ++i) {
    	v = automaton.t[v].to[s[i]];
    	cnt[i + 1] = automaton.t[v].num;
    }

    vector<pii> ans;
    ans.pb({sz(s), 1});
    int j = p.back();
    while (j > 0) {
    	ans.pb({j, cnt[j]});
    	j = p[j - 1];
    }

    reverse(all(ans));
    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i) {
    	cout << ans[i].first << " " << ans[i].second << "\n";
    }
 
}