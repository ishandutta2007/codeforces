#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &(x))
#define ll long long
#define vi vector<int>
#define pb push_back
const int N = 2e5 + 10;
int factor[N], phi[N];
void pre(){
    for(int i = 2;i*i<N;i++) if(!factor[i]) for(int j = i*i;j<N;j+=i) factor[j] = i;
    for(int i = 2;i<N;i++) if(!factor[i]) factor[i] = i;
    phi[1] = 1;
    for(int i = 2;i < N; i++){
    	int p = factor[i], x = i/p;
    	phi[i] = (x % p == 0) ? p * phi[x] : (p - 1) * phi[x];
    }	
}
int mod;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
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
inline int solve(int a, int b, int m){
	int g = __gcd(a, m);
	a /= g; m /= g; b /= g;
	mod = m;
	return mul(b, powr(a, phi[m] - 1));
}
vector<int> nums[N], divisors, vec;
int dp[N], lst[N];
bool notvalid[N];
int main(){
	pre();
 	int n, m, x;
 	sd(n); sd(m);
 	for(int i = 1; i <= m; i++) if(m % i == 0) divisors.pb(i);
 	for(int i =1; i <= n; i++){
 		sd(x); notvalid[x] = 1;
 	}
 	for(int i = 0; i < m; i++){
 		if(!notvalid[i]) nums[__gcd(i, m)].pb(i);
 	}
 	int mxi = 0, mxdp = 0;
 	for(int d : divisors){
 		if(nums[d].empty()) continue;
 		int k = nums[d].size();
 		dp[d] = k; lst[d] = 0;
 		for(int d1 : divisors){
 			if(d1 != d && d % d1 == 0){
 				if(dp[d1] + k > dp[d]){
 					dp[d] = dp[d1] + k;
 					lst[d] = d1;
 				}
 			}
 		}
 		if(dp[d] > mxdp){ mxdp = dp[d]; mxi = d;}
 	}
 	while(mxi){
 		for(int j : nums[mxi]) vec.pb(j);
 		mxi = lst[mxi];
 	}
 	vec.pb(1);
 	reverse(vec.begin(), vec.end());
 	printf("%d\n", mxdp);
 	for(int i = 0; i < vec.size() - 1; i++){
 		printf("%d ", solve(vec[i], vec[i + 1], m));
 	}
}