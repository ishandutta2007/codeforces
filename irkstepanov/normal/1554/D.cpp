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

const ll inf = 1e18;

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int tt;
    cin >> tt;
    while (tt--) {
    	int n;
    	cin >> n;
    	if (n == 1) {
    		cout << "a\n";
    	} else {
    		for (int i = 0; i < n / 2; ++i) {
    			cout << 'a';
    		}
    		cout << 'b';
    		if (n & 1) {
    			cout << 'c';
    		}
    		for (int i = 0; i < n / 2 - 1; ++i) {
    			cout << 'a';
    		}
    		cout << "\n";
    	}
    }

}