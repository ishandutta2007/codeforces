#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5,M=3e5+5;
struct edge{
	int u,v,w;
}e[M];
bool operator<(const edge&a,const edge&b){
	return a.w<b.w;
}
int n,m,ans;
int f[N],g[N];
stack<int>st;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=m;++i){
		if(!g[e[i].v]){
			st.push(e[i].v);
		}
		g[e[i].v]=max(g[e[i].v],f[e[i].u]+1);
		if(e[i].w!=e[i+1].w){
			while(!st.empty()){
				f[st.top()]=max(f[st.top()],g[st.top()]);
				g[st.top()]=0;
				st.pop();
			}
		}
	}
	for(int i=1;i<=n;++i){
		ans=max(ans,f[i]);
	}
	printf("%d",ans);
	return 0;
}