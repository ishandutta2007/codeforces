#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

vector<int> p_func(const string& s) {
	int n = sz(s);
	vector<int> p(n);
	for (int i = 1; i < n; ++i) {
		int j = p[i - 1];
		while (j && s[i] != s[j]) {
			j = p[j - 1];
		}
		if (s[i] == s[j]) {
			++j;
		}
		p[i] = j;
	}
	return p;
}

const int nmax = 110;

bool dp[nmax][26][nmax];
pii pr[nmax][26][nmax];

int main() {
    
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int sigma;
    cin >> sigma;

    string t;
    cin >> t;

    vector<int> p = p_func(t);
    int l = sz(t);

    vector<vector<int> > automaton(l + 1, vector<int>(sigma));

    for (int i = 0; i <= l; ++i) {
    	for (int c = 0; c < sigma; ++c) {
    		int j = i;
    		while (j && t[j] - 'a' != c) {
    			j = p[j - 1];
    		}
    		if (t[j] - 'a' == c) {
    			++j;
    		}
    		automaton[i][c] = j;
    	}
    }

    string need;
    cin >> need;

    vector<bool> f(n, false);
    for (int i = 0; i < sz(need); ++i) {
    	if (need[i] == '1') {
    		f[i + sz(t) - 1] = true;
    	}
    }

    for (int c = 0; c < sigma; ++c) {
    	if (t[0] - 'a' == c) {
    		dp[0][c][1] = true;
    	} else {
    		dp[0][c][0] = true;
    	}
    }
    for (int c = 0; c < sigma; ++c) {
    	if (f[0]) {
    		for (int val = 0; val < sz(t); ++val) {
    			dp[0][c][val] = false;
    		}
    	} else {
    		dp[0][c][sz(t)] = false;
    	}
    }

    for (int i = 1; i < n; ++i) {
    	for (int c1 = 0; c1 < sigma; ++c1) {
    		for (int val = 0; val <= sz(t); ++val) {
    			if (!dp[i - 1][c1][val]) {
    				continue;
    			}
    			for (int c2 = 0; c2 < sigma; ++c2) {
    				int nx = automaton[val][c2];
    				dp[i][c2][nx] = true;
    				pr[i][c2][nx] = {c1, val};
    			}
    		}
    	}

    	for (int c = 0; c < sigma; ++c) {
    		if (f[i]) {
    			for (int val = 0; val < sz(t); ++val) {
    				dp[i][c][val] = false;
    			}
    		} else {
    			dp[i][c][sz(t)] = false;
    		}
    	}
    }

    /*for (int i = 0; i < n; ++i) {
    	for (int c = 0; c < sigma; ++c) {
    		for (int val = 0; val <= sz(t); ++val) {
    			if (dp[i][c][val]) {
    				cout << i << " " << c << " " << val << endl;
    			}
    		}
    	}
    }*/

    int c = -1, val;

    for (int cc = 0; cc < sigma; ++cc) {
    	for (int vval = 0; vval <= sz(t); ++vval) {
    		if (dp[n - 1][cc][vval]) {
    			c = cc, val = vval;
    		}
    	}
    }

    if (c == -1) {
    	cout << "No solution\n";
    	return 0;
    }

    vector<int> ans;
    for (int i = n - 1; i >= 0; --i) {
    	ans.pb(c);
    	if (i == 0) {
    		break;
    	}
    	pii q = pr[i][c][val];
    	c = q.first, val = q.second;
    }

    reverse(all(ans));
    for (int x : ans) {
    	cout << char(x + 'a');
    }
    cout << "\n";
    
}