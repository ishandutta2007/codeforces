#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ld m, n, ans = 0;
	cin >> m >> n;
	for(ll i = 1; i <= m; i++)
		ans += i * (pow(i / m, n) - pow((i - 1) / m, n));
	cout << ans << endl;
}