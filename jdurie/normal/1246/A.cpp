#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, p;
	cin >> n >> p;
	ll ans = 1;
	while(true) {
		n -= p;
		if(n <= 0) {
			ans = -1;
			break;
		}
		if(n >= ans && __builtin_popcount(n) <= ans)
			break;
		ans++;
	}
	cout << ans << endl;
	return 0;
}