#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
#define int long long
using namespace std;
using ll = int64_t;
const int maxn = 1<<17, mod = 1000000007;
int lp[maxn];
vector<int> primes;
void sieve() {
	lp[1] = 0;
	for(int i = 2; i < maxn; i++) {
		if(!lp[i]) {
			lp[i] = i;
			primes.push_back(i);
		}
		for(int j = 0; j < primes.size() && primes[j] <= lp[i] && primes[j]*1ll*i < maxn; j++)
			lp[primes[j]*i] = primes[j];
	}
}
int n, k, t;
ll ans = 0;
map<int, int> cnt;
const int inf = 1<<20;
void process(int x) {
	int R = 1, C = 1;
	for(int l; l = lp[x];) {
		int pw = 0;
		while(x%l == 0) pw++, x/=l;
		pw %= k;
		if(!pw) continue;
		int a = 1, b = 1;
		for(int i = 0; i < pw; i++) a = min(a*l, inf);
		for(int i = pw; i < k; i++) b = min(b*l, inf);
		R = min(R*a, inf);
		C = min(C*b, inf);
	}
	if(C != inf)
	ans += cnt[C];
	if(R != inf)
	cnt[R]++;
}
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	sieve();
	for(cin >> n >> k; n--;)
		cin >> t, process(t);
	cout << ans << '\n';
}