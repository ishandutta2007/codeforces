#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 10, mod = 1e9 + 7;
int fact[N], invfact[N];
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (((ll) x) * y) % mod;}
inline int powr(int a, ll b){
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}
int factor[N], mu[N];
void pre(){
	fact[0] = invfact[0] = 1;
	for(int i = 1;i < N; i++) fact[i] = mul(i, fact[i - 1]);
	invfact[N - 1] = inv(fact[N - 1]);
	for(int i = N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
	assert(invfact[1] == 1);
	for(int i = 2;i*i<N;i++) if(!factor[i]) for(int j = i*i;j<N;j+=i) factor[j] = i;
    for(int i = 2;i<N;i++) if(!factor[i]) factor[i] = i;
    mu[1] = 1;
    for(int i = 2;i < N; i++){
    	int p = factor[i], x = i/p;
    	mu[i] = (x % p == 0) ? 0 : -mu[x];
    }
}
inline int C(int n, int k){
	if(n < k || k < 0) return 0;
	return mul(fact[n], mul(invfact[k], invfact[n - k]));
}
int freq[N], cnt[N], pw2[N];
int main(){
	pre();
	int n, x; 
	scanf("%d", &n);
	pw2[0] = 1;
	for(int i = 1; i < N; i++) pw2[i] = mul(2, pw2[i - 1]);
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		freq[x]++;
	}
	for(int i = 1; i < N; i++)
		for(int j = i; j < N; j += i)
			cnt[i] += freq[j];
	int ans = 0;
	for(int i = 2; i < N; i++){
			int x = 0, l = 1;
			for(int d = i; d < N; d += i, l++){
				int f = cnt[d] ? mul(cnt[d], pw2[cnt[d] - 1]) : 0;
				if(mu[l] == -1) x = sub(x, f);
				else if(mu[l] == 1) x = add(x, f);
			}
			ans = add(ans, mul(i, x));
		}
	cout << ans;
}