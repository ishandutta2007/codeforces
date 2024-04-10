#include<bits/stdc++.h>
using namespace std;
const int M=1<<16;
int n;
int a[M],b[M],c[M],vis[M];
vector<int>g[M];
queue<int>q;
void work(){
	scanf("%d",&n);
	for(int i=0;i<1<<n;++i)vis[i]=2,g[i].clear(),a[i]=0;
	for(int i=0,u,v;i<n*(1<<n-1);++i){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vis[0]=0;
	for(int i=0;i<n;++i)q.push(g[0][i]),vis[g[0][i]]=0,a[g[0][i]]=1<<i;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:g[u]){
			if(!vis[v])continue;
			a[v]|=a[u];
			vis[v]--;
			if(!vis[v])q.push(v);
		}
	}
	for(int i=0;i<1<<n;++i)b[a[i]]=i;
	for(int i=0;i<1<<n;++i)printf("%d%c",b[i]," \n"[i==(1<<n)-1]);
	if((1<<n)%n!=0)puts("-1");
	else {
		for(int i=1;i<1<<n;++i){
			c[i]=c[i^(i&-i)]^int(log2(i&-i));
		}
		for(int i=0;i<1<<n;++i){
			printf("%d%c",c[a[i]]," \n"[i==(1<<n)-1]);
		}
	}
}
int main(){
	int T;
	for(scanf("%d",&T);T;T--)work();
	return 0;
}