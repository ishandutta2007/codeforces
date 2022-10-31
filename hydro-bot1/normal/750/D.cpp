// Hydro submission #618919951edf93b3ad658702@1636374934172
#include<bits/stdc++.h>
using namespace std;
#define N 50
const int dx[8]={0,1,1,1,0,-1,-1,-1};
const int dy[8]={1,1,0,-1,-1,-1,0,1};
int n,res=0,a[N];
map<int,map<int,bool> > v;
map<int,map<int,map<int,map<int,bool> > > > vis;
void dfs(int x,int y,int k,int opt) {
	if (k>n) return;
	if (vis[x][y][k][opt]==1) return;
	vis[x][y][k][opt]=1;
	for (int i=1;i<=a[k];i++) {
		x+=dx[opt]; y+=dy[opt];
		if (!v[x][y]) res++; 
		v[x][y]=1;
	}
	dfs(x,y,k+1,(opt-1+8)%8);
	dfs(x,y,k+1,(opt+1)%8);
}
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",a+i);
	dfs(0,0,1,0);
	printf("%d\n",res);
	return 0;
}