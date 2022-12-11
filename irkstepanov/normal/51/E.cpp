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

vector<vector<ll> > operator*(const vector<vector<ll> >& a, const vector<vector<ll> >& b) {
	int n = sz(a);
	vector<vector<ll> > c(n, vector<ll>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}

int n;
vector<vector<ll> > a, b, c;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int m;
    cin >> m;
    a = vector<vector<ll> >(n, vector<ll>(n));
    vector<int> deg(n);
    
    while (m--) {
    	int u, v;
    	cin >> u >> v;
    	--u, --v;
    	a[u][v] = a[v][u] = 1;
    	++deg[u], ++deg[v];
    }

    b = a * a;
    c = b * a;

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		if (!a[i][j]) {
    			continue;
    		}
    		for (int k = 0; k < n; ++k) {
    			if (j == k || !a[i][k]) {
    				continue;
    			}
    			ll val = c[j][k];
    			val -= b[i][j];
    			val -= b[i][k];
    			//cout << "!" << val << endl;
    			if (a[j][k]) {
    				val -= deg[k] - 2;
    				val -= deg[j] - 1;
    			}
    			ans += val;
    		}
    	}
    }

    assert(ans % 10 == 0);
    cout << ans / 10 << "\n";

}