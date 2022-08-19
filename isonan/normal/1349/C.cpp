#include <cstdio>

int n,m,q,Q[1000001][2],h,t;
long long dis[1001][1001];
bool map[1001][1001];
void upd(int x,int y,long long dis){
	if(::dis[x][y]!=1e18)return;
	::dis[x][y]=dis;
	++t;
	Q[t][0]=x;
	Q[t][1]=y;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%1d",&map[i][j]),dis[i][j]=1e18;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(i>1&&map[i-1][j]==map[i][j])dis[i][j]=0;
			if(j>1&&map[i][j-1]==map[i][j])dis[i][j]=0;
			if(i<n&&map[i+1][j]==map[i][j])dis[i][j]=0;
			if(j<m&&map[i][j+1]==map[i][j])dis[i][j]=0;
			if(!dis[i][j]){
				++t;
				Q[t][0]=i;
				Q[t][1]=j;
			}
		}
	while(h<t){
		++h;
		int x=Q[h][0],y=Q[h][1];
		if(x>1)upd(x-1,y,dis[x][y]+1);
		if(y>1)upd(x,y-1,dis[x][y]+1);
		if(x<n)upd(x+1,y,dis[x][y]+1);
		if(y<m)upd(x,y+1,dis[x][y]+1);
	}
	long long t;
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d%lld",&x,&y,&t);
		if(t<=dis[x][y])printf("%d\n",map[x][y]);
		else printf("%d\n",map[x][y]^((t-1ll*dis[x][y])&1));
	}
}