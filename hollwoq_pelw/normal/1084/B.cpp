#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define rnd(n) fixed << setprecision(n)

const int mod = 998244353, mod2 = 1e+7;

int main(){
    IOS;
	ll n, k, s = 0, mn = LLONG_MAX, a;
	cin >> n >> k;
	for (int i = 0; i < n; i++){
	    cin >> a;
	    mn = min(mn, a);
	    s += a;
	}
	if (s < k) cout << -1;
	else cout << min(mn, (s-k)/n);
    return 0;
}