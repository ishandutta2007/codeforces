#include <bits/stdc++.h>
using namespace std;
#define mod 998244353

unsigned long long n, memo[1000005], memf[1000005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	fill_n(memo, 1000005, 1);
	fill_n(memf, 1000005, 1);
	for(uint32_t i = 2; i <= n; i++)
			memf[i] = (i * memf[i - 1])%mod;
	for(uint32_t i = 2; i <= n; i++)
			memo[i] = (i * (memo[i - 1] + memf[i - 1] - 1))%mod;

	cout << (memo[n]%mod);
}