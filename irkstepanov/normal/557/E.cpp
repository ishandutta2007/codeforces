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

const int alpha = 2;

struct node {
	int to[alpha];
	int term;
	int cnt;
	node() {
		memset(to, -1, sizeof(to));
		term = cnt = 0;
	}
};

vector<node> t;

void add(const string& s, vector<char>& where) {
	int v = 0;
	for (int i = 0; i < sz(s); ++i) {
		int c = s[i] - 'a';
		if (t[v].to[c] == -1) {
			t[v].to[c] = sz(t);
			t.pb(node());
		}
		v = t[v].to[c];
		if (where[i]) {
			++t[v].term;
		}
	}
}

void dfs(int v) {
	t[v].cnt = t[v].term;
	for (int c = 0; c < alpha; ++c) {
		int u = t[v].to[c];
		if (u == -1) {
			continue;
		}
		dfs(u);
		t[v].cnt += t[u].cnt;
	}
}

void kth(int v, int k) {
	k -= t[v].term;
	if (k <= 0) {
		return;
	}
	for (int c = 0; c < alpha; ++c) {
		int u = t[v].to[c];
		if (u == -1) {
			continue;
		}
		if (t[u].cnt >= k) {
			cout << char(c + 'a');
			kth(u, k);
			break;
		} else {
			k -= t[u].cnt;
		}
	}
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin >> s;
    int n = sz(s);

    vector<vector<char> > a(n, vector<char>(n, false));
    for (int len = 1; len <= n; ++len) {
    	for (int i = 0; i + len - 1 < n; ++i) {
    		int j = i + len - 1;
    		if (s[i] != s[j]) {
    			continue;
    		}
    		if (i + 2 < j - 2) {
    			a[i][j] = a[i + 2][j - 2];
    		} else {
    			a[i][j] = true;
    		}
    	}
    }

    t.pb(node());
    for (int i = 0; i < n; ++i) {
    	int lst = -1;
    	for (int j = i; j < n; ++j) {
    		if (a[i][j]) {
    			lst = j;
    		}
    	}
    	string t = s.substr(i, lst - i + 1);
    	vector<char> where;
    	for (int j = i; j <= lst; ++j) {
    		where.pb(a[i][j]);
    	}
    	add(t, where);
    }

    dfs(0);

    int k;
    cin >> k;

    kth(0, k);
    cout << "\n";

}