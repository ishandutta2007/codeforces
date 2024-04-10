#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
int n,s[100005],deg[100005],v[200005];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",s+i),deg[i]=0;
		int c=0;
		for(int i=1;i<=n-1;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			deg[x]++,deg[y]++;
		}
		for(int i=1;i<=n;i++) for(int j=0;j<deg[i]-1;j++)v[c++]=s[i];
		std::sort(v,v+c,std::greater<int>());
		LL ans=0;
		for(int i=1;i<=n;i++)ans+=s[i];
		for(int i=0;i<n-1;i++){
			printf("%lld ",ans);
			ans+=v[i];
		}
		puts("");
	}
}