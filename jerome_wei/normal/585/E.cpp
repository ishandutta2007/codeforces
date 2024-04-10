#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/* math */
const int N = 5e5+5, M = 1e7+7;
int mu[M], prime[M], pcnt, v[M];
inline void sieve(int n=1e7){
	mu[1]=1;for(int i=2;i<=n;i++){
		if(!v[i])mu[i]=-1,prime[++pcnt]=i;
		for(int j=1;j<=pcnt&&1ll*i*prime[j]<=n;j++){
			v[i*prime[j]]=1;
			if(i%prime[j])
				mu[i*prime[j]]=-mu[i];
			else {
				mu[i*prime[j]]=0;
				break;
			}
		}
	}
}
int cnt[M],n,pw[N];

int main()
{
	cin >> n;
	sieve();pw[0]=1;
	for(int i=1;i<=n;i++){
		int d;scanf("%d",&d);
		cnt[d]++;pw[i]=mul(pw[i-1],2);
	}
	for(int i=1;i<=10000000;i++){
		if(mu[i]!=0)for(int j=i*2;j<=10000000;j+=i){
			cnt[i]+=cnt[j];
		}
	}
	int ans=0;
	for(int i=1;i<=10000000;i++){
		if(mu[i]>0){
			ans=sub(ans, mul(n-cnt[i], sub(pw[cnt[i]],1)));
		}else if(mu[i]<0){
			ans=add(ans, mul(n-cnt[i], sub(pw[cnt[i]],1)));
		}
	}
	cout << ans << endl;
}