#include <cmath> 
#include <cstdio>
#include <cstring>
#include <algorithm>

int t,n,cnt[2000010],count[2000010];
long long cando[2000010];
bool f(int s,int a){
	return (s==1)?1:((s-(a%s))%s)<=(a/(s-1));
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		memset(cnt,0,(n+1)<<2);
		memset(count,0,(n+1)<<2);
		for(int i=1;i<=n;i++)cando[i]=0;
		for(int i=1,tem;i<=n;i++)scanf("%d",&tem),++cnt[tem];
		int mn=n+1;
		for(int i=1;i<=n;i++)++count[cnt[i]],mn=cnt[i]?std::min(mn,cnt[i]+1):mn;
		for(int i=1;i<=n;i++)
			if(count[i])
				for(int j=1;j<=mn;j++)
					if(!f(j,i))cando[j]=-1;
					else if(~cando[j])cando[j]+=1ll*((i+j-1)/j)*count[i];
		long long ans=1ll*n*n;
		for(int i=1;i<=mn;i++)if(~cando[i])ans=std::min(ans,cando[i]);
		printf("%lld\n",ans);
	}
}