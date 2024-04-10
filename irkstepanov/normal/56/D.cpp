#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;
typedef long long ll;

const int inf = 1e9;

const int sigma = 26;

struct datum {
	string type;
	int pos;
	char l;
};

int main() {

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s, t;
    cin >> s >> t;

    int m = sz(t);
    int n = sz(s);

    vector<vector<int> > dp(n + 1, vector<int>(m + 1, inf));
    vector<vector<int> > p(n + 1, vector<int>(m + 1, inf));
    for (int i = 0; i <= m; ++i) {
    	dp[0][i] = i;
    }

    for (int i = 0; i < sz(s); ++i) {
    	vector<int> pos(sigma, -1);
    	dp[i + 1][0] = i + 1;
    	p[i + 1][0] = -1;
    	for (int j = 1; j <= m; ++j) {
    		if (dp[i + 1][j] > dp[i][j] + 1) { // delete s[i]
    			dp[i + 1][j] = dp[i][j] + 1;
    			p[i + 1][j] = -1;
    		}
    		if (dp[i + 1][j] > dp[i][j - 1] + 1) { // change s[i]
    			dp[i + 1][j] = dp[i][j - 1] + 1;
    			p[i + 1][j] = -2;
    		}
    		pos[t[j - 1] - 'A'] = j - 1;
    		int x = pos[s[i] - 'A'];
    		if (x != -1 && dp[i + 1][j] > dp[i][x] + j - x - 1) { // match s[i]
    			dp[i + 1][j] = dp[i][x] + j - x - 1;
    			p[i + 1][j] = x;
    		}
    	}
    }

    cout << dp[n][m] << endl;
    int i = n, j = m;
    vector<datum> ans;
    while (i > 0) {
    	if (p[i][j] == -1) {
    		ans.pb({"DELETE", i, '-'});
    		--i;
    	} else if (p[i][j] == -2) {
    		ans.pb({"REPLACE", i, t[j - 1]});
    		--i;
    		--j;
    	} else {
    		//cout << "NU " << i << " " << j << endl;
    		int curr = p[i][j];
    		for (int k = curr + 1, u = i + 1; k < j; ++k, ++u) {
    			ans.pb({"INSERT", u, t[k]});
    		}
    		--i;
    		j = curr;
    	}
    }
    for (int k = j - 1; k >= 0; --k) {
    	ans.pb({"INSERT", 1, t[k]});
    }

    for (int i = 0; i < sz(ans); ++i) {
    	cout << ans[i].type << " " << ans[i].pos;
    	if (ans[i].type != "DELETE") {
    		cout << " " << ans[i].l;
    	}
    	cout << "\n";
    }

}