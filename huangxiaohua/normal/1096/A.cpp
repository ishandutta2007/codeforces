#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

int i,j,k,n,m,t,sb,l;
ll res,c[5550][5550],sum,f[105][5050],pre[105][5050],inv[6666];
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&l,&j);
		printf("%lld %lld\n",l,l*2ll);
	}
}