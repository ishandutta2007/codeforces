#include<bits/stdc++.h>
const int MAXN=100,dx[]={0,0,-1,1},dy[]={-1,1,0,0};
int w,h,n;
bool a[MAXN+5][MAXN+5][4],vis[MAXN+5][MAXN+5];
int tot;
int s[MAXN+5];
int dfs(int x,int y){
	if(vis[x][y])
		return 0;
	vis[x][y]=1;
	int ans=0;
	for(int i=0;i<4;++i){
		int x1=x+dx[i],y1=y+dy[i];
		if(a[x][y][i]||x1<1||y1<1||x1>w||y1>h)
			continue;
		ans+=dfs(x1,y1);
	}
	return ans+1;
}
int main(){
	scanf("%d%d%d",&w,&h,&n);
	for(int i=1;i<=n;++i){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2)
			for(int j=y1+1;j<=y2;++j){
				a[x1][j][3]=1;
				a[x1+1][j][2]=1;
			}
		else
			for(int j=x1+1;j<=x2;++j){
				a[j][y1][1]=1;
				a[j][y1+1][0]=1;
			}
	}
	for(int i=1;i<=w;++i)
		for(int j=1;j<=h;++j)
			if(!vis[i][j])
				s[++tot]=dfs(i,j);
	std::sort(s+1,s+tot+1);
	for(int i=1;i<=tot;++i)
		printf("%d ",s[i]);
	return 0;
}