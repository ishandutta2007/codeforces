#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;


int main() {
	ll n, m, ans = 0;
	cin >> n >> m;
	while(n > 0) if(++ans % m) n--;
	cout << ans << endl;
	return 0;
}