#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

const int nmax = 1010;

string a[nmax];

int up[nmax][nmax], dw[nmax][nmax], rg[nmax][nmax], lf[nmax][nmax];

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }

    for (int i = 1; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		up[i][j] = up[i - 1][j];
    		if (a[i - 1][j] == '*') {
    			++up[i][j];
    		}
    	}
    }

    for (int i = n - 2; i >= 0; --i) {
    	for (int j = 0; j < m; ++j) {
    		dw[i][j] = dw[i + 1][j];
    		if (a[i + 1][j] == '*') {
    			++dw[i][j];
    		}
    	}
    }

    for (int j = 1; j < m; ++j) {
    	for (int i = 0; i < n; ++i) {
    		lf[i][j] = lf[i][j - 1];
    		if (a[i][j - 1] == '*') {
    			++lf[i][j];
    		}
    	}
    }

    for (int j = m - 2; j >= 0; --j) {
    	for (int i = 0; i < n; ++i) {
    		rg[i][j] = rg[i][j + 1];
    		if (a[i][j + 1] == '*') {
    			++rg[i][j];
    		}
    	}
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		if (a[i][j] != '*') {
    			continue;
    		}
    		ans += ll(up[i][j]) * (lf[i][j] + rg[i][j]);
    		ans += ll(dw[i][j]) * (lf[i][j] + rg[i][j]);
    	}
    }

    cout << ans << "\n";

}