#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n;
typedef long long ll;
char c[1005];int d[1005];
int x[2005],y[2005],xtot=0,ytot=0;
int vis[2005][2005];
int qx[4000005],qy[4000005];int p,q;
ll bfs(int cx,int cy){
	ll ans=0;
	p=q=0;
	qx[q]=cx;qy[q++]=cy;vis[cx][cy]=2;
	while(p!=q){
		int nx=qx[p],ny=qy[p];p++;
		ans+=1ll*(x[nx+1]-x[nx])*(y[ny+1]-y[ny]);
		if(nx+1<xtot && !vis[nx+1][ny]){
			qx[q]=nx+1,qy[q++]=ny,vis[nx+1][ny]=2;
		}
		if(nx-1>=1 && !vis[nx-1][ny]){
			qx[q]=nx-1,qy[q++]=ny,vis[nx-1][ny]=2;
		}
		if(ny+1<ytot && !vis[nx][ny+1]){
			qx[q]=nx,qy[q++]=ny+1,vis[nx][ny+1]=2;
		}
		if(ny-1>=1 && !vis[nx][ny-1]){
			qx[q]=nx,qy[q++]=ny-1,vis[nx][ny-1]=2;
		}
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		char t;while((t=getchar())<'A'||t>'Z');
		c[i]=t;scanf("%d",&d[i]);
	}
	int xx=0,yy=0,cx,cy;
	x[++xtot]=0,x[++xtot]=1;
	y[++ytot]=0,y[++ytot]=1;
	for (int i=1;i<=n;i++){
		if(c[i]=='U')yy+=d[i];
		if(c[i]=='D')yy-=d[i];
		if(c[i]=='L')xx-=d[i];
		if(c[i]=='R')xx+=d[i];
		x[++xtot]=xx,x[++xtot]=xx+1;
		y[++ytot]=yy,y[++ytot]=yy+1;
	}
	sort(x+1,x+1+xtot);
	xtot=unique(x+1,x+1+xtot)-x-1;
	sort(y+1,y+1+ytot);
	ytot=unique(y+1,y+1+ytot)-y-1;
	xx=yy=0;
	cx=lower_bound(x+1,x+1+xtot,0)-x;
	cy=lower_bound(y+1,y+1+ytot,0)-y;
	vis[cx][cy]=1;
	for (int i=1;i<=n;i++){
		if(c[i]=='U'){
			yy+=d[i];
			for(;vis[cx][cy]=1,y[cy]!=yy;cy++);
		}if(c[i]=='D'){
			yy-=d[i];
			for(;vis[cx][cy]=1,y[cy]!=yy;cy--);
		}if(c[i]=='L'){
			xx-=d[i];
			for(;vis[cx][cy]=1,x[cx]!=xx;cx--);
		}if(c[i]=='R'){
			xx+=d[i];
			for(;vis[cx][cy]=1,x[cx]!=xx;cx++);
		}
	}
	ll ans=1ll*(x[xtot]-x[1])*(y[ytot]-y[1]);
	for (int i=1;i<xtot;i++){
		if(!vis[i][1])ans-=bfs(i,1);
		if(!vis[i][ytot-1])ans-=bfs(i,ytot-1);
	}
	for (int j=1;j<ytot;j++){
		if(!vis[1][j])ans-=bfs(1,j);
		if(!vis[xtot-1][j])ans-=bfs(xtot-1,j);
	}
	cout<<ans<<endl;
	return 0;
}