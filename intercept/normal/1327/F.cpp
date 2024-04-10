#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int M=5e5+9;
int n,k,m,ans=1;
int l[M],r[M],x[M],f[M],s[M],lim[M],cnt[M],mx;
int main(){
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=m;++i)scanf("%d%d%d",&l[i],&r[i],&x[i]);
	for(int w=0;w<k;++w){
		s[0]=f[0]=1;mx=0;
		for(int i=1;i<=n;++i)f[i]=s[i]=lim[i]=cnt[i]=0;
		for(int i=1;i<=m;++i){
			if(!(x[i]>>w&1))lim[r[i]]=max(lim[r[i]],l[i]);
			else cnt[l[i]]++,cnt[r[i]+1]--;
		}
		for(int i=1;i<=n;++i){
			cnt[i]+=cnt[i-1];
			if(!cnt[i])f[i]=s[i-1];
			s[i]=(f[i]+s[i-1])%mod;
			while(lim[i]>mx)s[i]=(s[i]-f[mx]+mod)%mod,mx++;
		}
		ans=1ll*ans*s[n]%mod;
	}
	printf("%d\n",ans);
	return 0;
}