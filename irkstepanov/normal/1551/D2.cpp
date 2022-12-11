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

void kek(vector<vector<char> >& ans, int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (ans[i][j] == '.') {
				char letter;
				if (j % 2) {
					if (i % 4 < 2) {
						letter = 'e';
					} else {
						letter = 'f';
					}
				} else {
					if (i % 4 < 2) {
						letter = 'g';
					} else {
						letter = 'h';
					}
				}
				ans[i][j] = ans[i + 1][j] = letter;
			}
		}
	}
}

void lol(vector<vector<char> >& ans, int n, int m, int k, int i0) {
	int j = 0, i = i0;
	while (k--) {
		char letter;
		if (i % 2) {
			if (j % 4 == 0) {
				letter = 'c';
			} else {
				letter = 'd';
			}
		} else {
			if (j % 4 == 0) {
				letter = 'a';
			} else {
				letter = 'b';
			}
		}
		ans[i][j] = letter;
		ans[i][j + 1] = letter;
		++i;
		if (i == n) {
			i = i0;
			j += 2;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int tt;
    cin >> tt;

    while (tt--) {
    	int n, m, k;
    	cin >> n >> m >> k;
    	if (m % 2 == 0) {
    		if (n % 2 && k < m / 2) {
	    		cout << "NO\n";
	    		continue;
	    	}
	    	vector<vector<char> > ans(n, vector<char>(m, '.'));
	    	int i0 = 0;
	    	if (n % 2) {
	    		k -= m / 2;
	    		for (int j = 0; j < m / 2; ++j) {
	    			if (j % 2 == 0) {
	    				ans[0][j * 2] = 'a';
	    				ans[0][j * 2 + 1] = 'a';
	    			} else {
	    				ans[0][j * 2] = 'b';
	    				ans[0][j * 2 + 1] = 'b';
	    			}
	    		}
	    		i0 = 1;
	    	}
	    	if (k % 2) {
	    		cout << "NO\n";
	    	} else {
	    		cout << "YES\n";
	    		lol(ans, n, m, k, i0);
	    		kek(ans, n, m);
	    		for (int i = 0; i < n; ++i) {
	    			for (int j = 0; j < m; ++j) {
	    				cout << ans[i][j];
	    			}
	    			cout << "\n";
	    		}
	    	}
    	} else {
    		if (k % 2 == 0 && k <= n * (m / 2)) {
    			cout << "YES\n";
    			vector<vector<char> > ans(n, vector<char>(m, '.'));
    			lol(ans, n, m, k, 0);
    			kek(ans, n, m);
    			for (int i = 0; i < n; ++i) {
	    			for (int j = 0; j < m; ++j) {
	    				cout << ans[i][j];
	    			}
	    			cout << "\n";
	    		}
    		} else {
    			cout << "NO\n";
    		}
    	}
    	
    }

}