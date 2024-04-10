#include <algorithm>
#include <cstdio>
#include <cmath>

long long ans;
int n;
int s[1000001],S,nxt[1000001],pre[1000001];
int sum[1000001],val[1000001];
long long f(int l,int l2,int r2,int x){
	l2-=l+1,r2-=l;
	return std::max((r2/x)-std::max((l2/x),S),0);
}
int main(){
	for(n=1;;n++){
		if(scanf("%1d",s+n)==EOF)break;
		sum[n]=sum[n-1]+s[n];
	}
	--n;
	S=(int)sqrt(n);
	nxt[n+1]=n+1;
	for(int i=n;i;i--)nxt[i]=s[i+1]?i+1:nxt[i+1];
	for(int i=1;i<=n;i++)pre[i]=s[i-1]?i-1:pre[i-1];
	for(int i=1;i<=n;i++){
		for(int j=1,pos=s[i]?i:nxt[i];j<=S&&pos<=n;j++,pos=nxt[pos])
			ans+=f(i-1,pos,nxt[pos]-1,j);
	}
	for(int i=1;i<=S;i++){
		for(int j=0;j<=n;j++)val[j]=j-i*sum[j];
		std::sort(val,val+n+1);
		for(int j=0,cnt=0;j<=n;j++){
			if(j&&val[j]!=val[j-1])cnt=0;
			ans+=cnt;
			++cnt;
		}
	}
	printf("%lld\n",ans);
}