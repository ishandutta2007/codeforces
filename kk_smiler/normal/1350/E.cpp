#include <bits/stdc++.h>
#define ope operator
#define re register
#define il inline
using namespace std;
int T,n,m,k,Q,fx[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char ma[1010][1010];
long long st[1010][1010];
struct node{
	int x,y;
};
queue<node>q;
int main(){
	scanf("%d %d %d",&n,&m,&Q);
	for(int i=1;i<=n;i++) scanf("%s",ma[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		st[i][j]=LLONG_MAX/4;
		for(int k=0;k<4;k++){
			int xx=i+fx[k][0],yy=j+fx[k][1];
			if(xx<1||xx>n||yy<1||yy>m) continue;
			if(ma[xx][yy]==ma[i][j]) st[i][j]=0;
		}
		if(st[i][j]==0) q.push(node{i,j});
	}
	while(!q.empty()){
		node now=q.front();q.pop();
		for(int k=0;k<4;k++){
			int xx=now.x+fx[k][0],yy=now.y+fx[k][1];
			if(xx<1||xx>n||yy<1||yy>m) continue;
			if(st[xx][yy]>st[now.x][now.y]+1){
				st[xx][yy]=st[now.x][now.y]+1;
				q.push(node{xx,yy});
			}
		}
	}
	long long p;
	for(int i=1,x,y;i<=Q;i++){
		scanf("%d %d %lld",&x,&y,&p);
		if(st[x][y]>=p) printf("%c\n",ma[x][y]);
		else printf("%d\n",(ma[x][y]-'0')^((p-st[x][y])&1));
	}
}