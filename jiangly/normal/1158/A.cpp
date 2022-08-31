#include<bits/stdc++.h>
typedef long long ll;
const int MAXN=100005,MAXM=100005;
int n,m;
int b[MAXN],g[MAXM];
ll ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&b[i]);
	for(int i=1;i<=m;++i)
		scanf("%d",&g[i]);
	std::sort(b+1,b+n+1);
	std::sort(g+1,g+m+1);
	if(g[1]<b[n]){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;++i)
		ans+=1ll*b[i]*m;
	for(int i=2;i<=m;++i)
		ans+=g[i]-b[n];
	ans+=g[1]-b[g[1]==b[n]?n:n-1];
	printf("%I64d\n",ans);
	return 0;
}