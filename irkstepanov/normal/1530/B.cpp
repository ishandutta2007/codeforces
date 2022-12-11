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

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int tt;
    cin >> tt;

    while (tt--) {
    	int n, m;
    	cin >> n >> m;
    	vector<vector<int> > a(n, vector<int>(m, 0));
    	a[0][0] = 1;
    	for (int j = 2; j < m; j += 2) {
    		a[0][j] = 1;
    	}
    	for (int i = 2; i < n; i += 2) {
    		a[i][m - 1] = 1;
    	}
    	for (int j = m - 3; j >= 0; j -= 2) {
    		a[n - 1][j] = 1;
    	}
    	for (int i = n - 3; i >= 2; i -= 2) {
    		a[i][0] = 1;
    	}
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < m; ++j) {
    			cout << a[i][j];
    		}
    		cout << "\n";
    	}
    	cout << "\n";
    }

}