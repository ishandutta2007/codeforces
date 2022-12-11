#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

//typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;


typedef int ll;

const int nmax = 4040;

ll cost[nmax][nmax];
ll g[nmax][nmax];
ll pref[nmax][nmax];

int curr;

void f(int l, int r, int optl, int optr) {
	int m = (l + r) >> 1;
	int optm = -1;
	for (int i = optl; i <= optr && i <= m; ++i) {
		ll c = cost[i][m];
		if (i) {
			c += pref[curr - 1][i - 1];
		}
		if (optm == -1 || c < pref[curr][m]) {
			optm = i;
			pref[curr][m] = c;
		}
	}
	if (optm == -1) {
		if (m < r) {
			f(m + 1, r, optl, optr);
		}
	} else {
		if (l < m) {
			f(l, m - 1, optl, optm);
		}
		if (m < r) {
			f(m + 1, r, optm, optr);
		}
	}
}

int main() {
    
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		scanf("%d", &g[i][j]);
    	}
    }
    for (int i = 0; i < n; ++i) {
    	pref[i][0] = g[i][0];
    	for (int j = 1; j < n; ++j) {
    		pref[i][j] = pref[i][j - 1] + g[i][j];
    	}
    }

    for (int i = 0; i < n; ++i) {
    	for (int j = i + 1; j < n; ++j) {
    		cost[i][j] = cost[i][j - 1];
    		cost[i][j] += pref[j][j - 1];
    		if (i) {
    			cost[i][j] -= pref[j][i - 1];
    		}
    	}
    }

    for (int i = 0; i < n; ++i) {
    	pref[1][i] = cost[0][i];
    }
    for (curr = 2; curr <= k; ++curr) {
    	memcpy(pref[curr], pref[curr - 1], sizeof(pref[curr]));
    	f(0, n - 1, 0, n - 1);
    }

    cout << pref[k][n - 1] << "\n";

}