#include<bits/stdc++.h>
using namespace std;
int n,m,col[510];
bool vis[510][510];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) vis[i][i]=true;
	int u,v;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		vis[u][v]=true; vis[v][u]=true;
	}
	u=-1; v=-1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			if (!vis[i][j]){
				u=i; v=j;
				break;
			}
		if (u!=-1) break;
	}
	// cerr<<u<<' '<<v<<endl;
	if (u==-1){
		puts("Yes");
		for (int i=1;i<=n;i++) putchar('a');
	} else{
		for (int i=1;i<=n;i++) col[i]=1;
		for (int i=1;i<=n;i++){
			if (!vis[u][i]) col[i]=2;
			if (!vis[v][i]) col[i]=0;
		}
		bool ans=true;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (vis[i][j]!=(abs(col[i]-col[j])<=1)) ans=false;
		if (ans){
			puts("Yes");
			for (int i=1;i<=n;i++) putchar(col[i]+'a');
		} else puts("No");
	}
	return 0;
}