#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,a[110000],b[110000];
bool vis[110000][8];
void dfs(int u,int c){
	if (vis[u][c]) return;
	b[u-1]=c;
	if (u==n+1){
		for (int i=1;i<=n;i++) printf("%d ",b[i]);
		exit(0);
	}
	vis[u][c]=true;
	for (int i=1;i<=5;i++){
		if (a[u-1]>a[u]&&c>i) dfs(u+1,i);
		if (a[u-1]==a[u]&&c!=i) dfs(u+1,i);
		if (a[u-1]<a[u]&&c<i) dfs(u+1,i);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0]=INF; dfs(1,6); puts("-1");
	return 0;
}