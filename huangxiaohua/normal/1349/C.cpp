#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1050][1050],vis[1050][1050],sb[1050][1050];
queue<pair<int,int> >q;
ll x;
bool chk(int x,int y){
	int res=0;
	if(x>1){res|=a[x-1][y]==a[x][y];}
	if(x<n){res|=a[x+1][y]==a[x][y];}
	if(y>1){res|=a[x][y-1]==a[x][y];}
	if(y<m){res|=a[x][y+1]==a[x][y];}
	return res;
}

int main(){
	memset(sb,-1,sizeof(sb));
	scanf("%d%d%d",&n,&m,&t);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%1d",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(chk(i,j)){
				vis[i][j]=1;sb[i][j]=0;q.push({i,j});
			}
		}
	}
	while(!q.empty()){
		auto [x,y]=q.front();q.pop();k=sb[x][y];
		if(x<n&&!vis[x+1][y]){vis[x+1][y]=1;sb[x+1][y]=k+1;q.push({x+1,y});}
		if(x>1&&!vis[x-1][y]){vis[x-1][y]=1;sb[x-1][y]=k+1;q.push({x-1,y});}
		if(y<m&&!vis[x][y+1]){vis[x][y+1]=1;sb[x][y+1]=k+1;q.push({x,y+1});}
		if(y>1&&!vis[x][y-1]){vis[x][y-1]=1;sb[x][y-1]=k+1;q.push({x,y-1});}
	}
	while(t--){
		scanf("%d%d%lld",&i,&j,&x);
		if(sb[i][j]==-1||x<sb[i][j]){printf("%d\n",a[i][j]);continue;}
		printf("%d\n",a[i][j]^((x-sb[i][j])&1));
	}
}