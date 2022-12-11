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

//const int inf = 1e9;

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int tt;
    cin >> tt;

    while (tt--) {
    	ll k;
    	cin >> k;
    	ll curr = 1;
    	int ptr = 0;
    	ll sum = 0;
    	while (true) {
    		sum += curr;
    		++ptr;
    		if (sum >= k) {
    			break;
    		}
    		curr += 2;
    	}
    	sum -= curr;
    	ll rest = k - sum;
    	if (rest <= ptr) {
    		cout << rest << " " << ptr << "\n";
    	} else {
    		rest -= ptr;
    		cout << ptr << " " << ptr - rest << "\n";
    	}
    }

}