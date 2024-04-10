#include<bits/stdc++.h>
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
using namespace std;
const int N=100005;
vector<int>p[N];
int n,fa[N];
LL f[N],g[N],h[N];
void dfs(int x){
	for(int y:p[x]) if(y!=fa[x]){
		fa[y]=x;
		dfs(y);
	}
}
void dfs2(int x,LL v,LL vo){
	int c=0;
	for(int y:p[x]) if(y!=fa[x])c++;
	if(!c){
		f[x]=v;
		return;
	}
	f[x]=v-c*vo;
	for(int y:p[x]) if(y!=fa[x])dfs2(y,vo,vo*c+f[x]);
}
int main(){
	mt19937 ran(time(0)^reinterpret_cast<LL>(new char));
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n-1;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			p[x].push_back(y);
			p[y].push_back(x);
		}
		dfs(1);
		dfs2(1,0,1);
		for(int i=1;i<=n;i++)g[i]=f[i];
		g[1]++;
		dfs2(1,1,0);
		for(int i=1;i<=n;i++)h[i]=f[i];
		for(int i=1;i<=n;i++)p[i].clear();
		while(1){
			LL x,y;
			if(ran()%3==1){
				x=ran()%3,y=ran()%5-2;
			}
			else if(ran()%3==1){
				x=ran()%11,y=ran()%21-10;
			}
			else if(ran()%3<=1){
				x=ran()%51,y=ran()%101-50;
			}
			else{
				x=ran()%n,y=ran()%n*2-n;
			}
			for(int i=1;i<=n;i++)f[i]=g[i]*x+h[i]*y;
			bool flag=1;
			for(int i=1;i<=n;i++)flag&=f[i]>=-100000&&f[i]<=100000&&f[i]!=0;
			if(flag)break;
		}
		for(int i=1;i<=n;i++)printf("%lld ",f[i]);
		puts("");
	}
}