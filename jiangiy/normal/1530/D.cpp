#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=200005;
std::vector<int>p[N];
int n,rt,a[N],b[N];
bool vis[N],vt[N];
int dfs(int x,int u){
	vis[x]=1;
	b[x]=u;
	int t=x;
	for(int y:p[x]) if(y!=rt){
		t=dfs(y,t);
	}
	return t;
}
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)p[i].clear(),vis[i]=vt[i]=0;
		for(int i=1;i<=n;i++)scanf("%d",a+i),p[a[i]].push_back(i);
		for(int i=1;i<=n;i++) if(!vis[i]){
			int x=i;
			while(!vt[x])vt[x]=1,x=a[x];
			int y=a[x];
			while(y!=x&&p[y].size()==1)y=a[y];
			x=y;
			y=a[x];
			while(a[y]!=x)y=a[y];
			x=y;
			b[x]=dfs(rt=x,0);
		}
		int cnt=0;
		for(int i=1;i<=n;i++)cnt+=a[i]==b[i];
		printf("%d\n",cnt);
		for(int i=1;i<=n;i++)printf("%d ",b[i]);
		puts("");
	}
}