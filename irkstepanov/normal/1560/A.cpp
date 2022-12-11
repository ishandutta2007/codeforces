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

    vector<int> a;
    int lst = 0;
    int tt;
    cin >> tt;

    while (tt--) {
    	int k;
    	cin >> k;
    	while (sz(a) < k) {
    		++lst;
    		while (lst % 3 == 0 || lst % 10 == 3) {
    			++lst;
    		}
    		a.pb(lst);
    	}
    	cout << a[k - 1] << "\n";
    }

}