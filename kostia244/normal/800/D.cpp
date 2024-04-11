#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1000000, mod = 1e9 + 7;
void add(int &a, int b) {
	a += b;
	if(a >= mod) a -= mod;
}
int n, p[10], p2[maxn], S0[maxn], S1[maxn], S2[maxn], G[maxn];
inline int ith(int n, int i) {
	return (n/p[i])%10;
}
void transform(int *a) {
	for(int c = 0; c < 6; c++)
		for(int i = maxn; i--;)
			if(ith(i, c)!=9) add(a[i], a[i+p[c]]);
}
void inverse_transform(int *a) {
	for(int c = 0; c < 6; c++)
		for(int i = 0; i < maxn; i++)
			if(ith(i, c)!=9) add(a[i], mod-a[i+p[c]]);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	p2[0] = 1;
	p[0] = 1;
	for(int i = 1; i < 10; i++) p[i] = p[i-1]*10;
	for(int i = 1; i < maxn; i++) p2[i] = p2[i-1]*2ll%mod;
	cin >> n;
	for(int x, i = 0; i < n; i++) {
		cin >> x;
		add(S0[x], 1);
		add(S1[x], x);
		add(S2[x], x*1ll*x%mod);
	}
	for(int* x : {S0, S1, S2}) transform(x);
	for(int i = 0; i < maxn; i++) {
		int &t = G[i];
		t = S1[i]*1ll*S1[i]%mod;
		add(t, mod - S2[i]);
		if(S0[i] > 1)
			t = t*1ll*p2[S0[i]-2]%mod;
		if(S0[i])
			add(t, S2[i]*1ll*p2[S0[i]-1]%mod);
	}
	inverse_transform(G);
	ll ans = 0;
	for(int i = 0; i < maxn; i++) {
		ans ^= G[i]*1ll*i;	
	}
	cout << ans;
	return 0;
}