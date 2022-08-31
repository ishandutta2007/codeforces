#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define ll long long
#define sd(x) scanf("%d", &(x))
vi primes;
const int N = 1e6 + 10, mod =  1e9 + 7;
int factor[N], mu[N], phi[N];
vector<int> divs[N];
void pre(){
    for(int i = 2;i*i<N;i++) if(!factor[i]) for(int j = i*i;j<N;j+=i) factor[j] = i;
    for(int i = 2; i < N; i++) if(!factor[i]) factor[i] = i;
    mu[1] = phi[1] = 1;
    for(int i = 2;i < N; i++){
    	int p = factor[i], x = i/p;
    	mu[i] = (x % p == 0) ? 0 : -mu[x];
    	phi[i] = (x % p == 0) ? phi[x] * p : phi[x] * (p - 1);
    }	
    for(int i = 1; i < N; i++) divs[i].reserve(10);
    for(int i = 1; i < N; i++) for(int j = i; j < N; j += i) divs[j].pb(i);
}
int fact[N << 1], invfact[N << 1];
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
void prefact(){
	fact[0] = invfact[0] = 1;
	for(int i = 1;i < 2 * N; i++) fact[i] = mul(i, fact[i - 1]);
	invfact[2 * N - 1] = inv(fact[2 * N - 1]);
	for(int i = 2 * N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
	assert(invfact[1] == 1);
}
inline int C(int n, int k){
	if(n < k || k < 0) return 0;
	return mul(fact[n], mul(invfact[k], invfact[n - k]));
}
int cnt[N];
int main(){
	pre();
	prefact();
	int ans = 0;
	int n,  k, q, x;
	sd(n), sd(k), sd(q);
	for(int i = 1; i <= n; i++){
		sd(x);
		for(int d : divs[x]) cnt[d]++;
	}
	for(int i = 1; i < N; i++) ans = add(ans, mul(phi[i], C(cnt[i], k)));
	while(q--){
		sd(x);
		for(int d : divs[x]){
			cnt[d] ++;
			ans = add(ans, mul(sub(C(cnt[d], k), C(cnt[d] - 1, k)), phi[d]));
		}
		printf("%d\n", ans);	
	}	
}