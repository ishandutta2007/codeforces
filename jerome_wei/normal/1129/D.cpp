#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/*math*/
const int N=1e5+5;
const int BLK=400;
int n,qk,K;
int pre[N],lst[N],cnt[N],_tmp[N];
int tag[BLK],l[BLK],r[BLK],sum[BLK][N],ans[BLK];
int bl[N],f[N],dp[N],a[N];

inline void rebuild(int x){
	for(int k=l[x];k<=r[x];k++)sum[x][f[k]]=0;
	for(int k=l[x];k<=r[x];k++)f[k]+=tag[x];
	tag[x]=0;ans[x]=0;
	for(int k=l[x];k<=r[x];k++){
		sum[x][f[k]]=add(sum[x][f[k]],dp[k]);
		ans[x]=add(ans[x],f[k]<=qk?dp[k]:0);
	}
}
inline void upd(int x,int fff,int del=true){
	int b=bl[x];
	if(del){
		sum[b][f[x]]=sub(sum[b][f[x]],dp[x]);
		if(f[x]<=qk)ans[b]=sub(ans[b],dp[x]);
	}
	f[x]+=fff;
	sum[b][f[x]]=add(sum[b][f[x]],dp[x]);
	if(f[x]<=qk)ans[b]=add(ans[b],dp[x]);
}
inline void ADD(int L,int R,int f){
	if(bl[L]==bl[R]){
		rebuild(bl[L]);
		for(int k=L;k<=R;k++){
			upd(k,f);
		}
		return ;
	}
	rebuild(bl[L]);
	for(int k=L;k<=r[bl[L]];k++)upd(k,f);
	for(int k=bl[L]+1;k<=bl[R]-1;k++){
		if(f==1){
			int tk=qk-tag[k];
			ans[k]=sub(ans[k],sum[k][tk]);
			++tag[k];
		}else{
			--tag[k];
			int tk=qk-tag[k];
			ans[k]=add(ans[k],sum[k][tk]);
		}
	}
	rebuild(bl[R]);
	for(int k=l[bl[R]];k<=R;k++)upd(k,f);
}
inline int query(int x){
	int res=_tmp[x]+dp[x];
	for(int k=1;k<=bl[x]-1;k++)res=add(res,ans[k]);
	for(int k=l[bl[x]];k<x;k++)res=add(res,f[k]<=qk?dp[k]:0);
	return res;
}
int main()
{
	scanf("%d%d",&n,&qk);K=sqrt(n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pre[i]=lst[a[i]];lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		bl[i]=(i-1)/K+1;
		r[bl[i]]=max(r[bl[i]],i);
		if(!l[bl[i]])l[bl[i]]=i;
	}
	dp[1]=1;
	for(int i=1;i<=n;i++){
		if(i!=1&&pre[i]+1!=i){
			ADD(pre[i]+1,i-1,1);
		}
		if(pre[i])ADD(pre[pre[i]]+1,pre[i],-1);
		dp[i+1]=query(i);
		rebuild(bl[i]);
		upd(i,1);
	}
	cout<<dp[n+1]<<endl;
}