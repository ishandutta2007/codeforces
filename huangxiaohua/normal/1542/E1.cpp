#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,cur[6666],tmp[6666],nxd,tmp2[6666];
ll ans,lst,pre[6666],M;

int main(){
	scanf("%d%lld",&n,&M);
	cur[0]=1;
	tmp2[0]=1;
	for(t=2;t<=n;t++){
		nxd+=t-1;
		for(i=1;i<t;i++){
			memset(tmp,0,sizeof(tmp));
			pre[nxd+1]=0;
			for(j=nxd;j>=0;j--){pre[j]=(pre[j+1]+tmp2[j])%M;}
			for(j=0;j<=nxd;j++){tmp[j+i]=cur[j];}
			for(j=0;j<=nxd;j++){
				ans=(ans+tmp[j]*pre[j+1])%M;
				tmp2[j]=(tmp2[j]+tmp[j])%M;
			}
			ans=(ans+lst)%M;
		}
		lst=ans;
		for(i=0;i<=nxd;i++){cur[i]=tmp2[i];}
	}
	printf("%lld",ans);
}