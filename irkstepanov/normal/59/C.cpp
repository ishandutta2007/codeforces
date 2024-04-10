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

const int nmax = 100 * 100 + 200;

bool dp[nmax];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int k;
    cin >> k;

    string s;
    cin >> s;
    int n = sz(s);

    vector<bool> used(k, false);

    for (int i = 0; i < sz(s); ++i) {
    	int j = sz(s) - i - 1;
    	if ((s[i] == '?') ^ (s[j] == '?')) {
    		if (s[i] == '?') {
    			s[i] = s[j];
    		} else {
    			s[j] = s[i];
    		}
    	}
    	if (s[i] != '?') {
    		used[s[i] - 'a'] = true;
    	}
    	if (s[i] != s[j]) {
    		cout << "IMPOSSIBLE\n";
    		return 0;
    	}
    }

    for (int i = (sz(s) - 1) / 2; i >= 0; --i) {
    	if (s[i] != '?') {
    		continue;
    	}
    	int f = -1;
    	for (int j = k - 1; j >= 0; --j) {
    		if (!used[j]) {
    			f = j;
    			break;
    		}
    	}
    	if (f == -1) {
    		f = 0;
    	} else {
    		used[f] = true;
    	}
    	s[i] = s[sz(s) - 1 - i] = char(f + 'a');
    }
    for (int j = 0; j < k; ++j) {
    	if (!used[j]) {
    		cout << "IMPOSSIBLE\n";
    		return 0;
    	}
    }

    cout << s << endl;

}