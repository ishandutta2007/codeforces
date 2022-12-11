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
    	int n, m, k;
    	cin >> n >> m >> k;
    	if (m % 2 == 0) {
    		if (n % 2 && k < m / 2) {
	    		cout << "NO\n";
	    		continue;
	    	}
	    	if (n % 2) {
	    		k -= m / 2;
	    		--n;
	    	}
	    	if (k % 2) {
	    		cout << "NO\n";
	    	} else {
	    		cout << "YES\n";
	    	}
    	} else {
    		if (k % 2 == 0 && k <= n * (m / 2)) {
    			cout << "YES\n";
    		} else {
    			cout << "NO\n";
    		}
    	}
    	
    }

}