#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
//const int rlen=1<<18|1;
//inline char gc(){
//	static char buf[rlen],*ib,*ob;
//	(ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin));
//	return ib==ob?-1:*ib++;
//}
inline int read(){
	#define gc getchar
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
typedef pair<int,int> pii;
inline bool query(int x1,int y1,int x2,int y2){
	cout<<"? "<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
	return read();
}
const int N=60;
int n,f[N][N];
void dfs(int x,int y){
	for(ri nx,ny,i=0;i<3;++i){
		nx=x+i,ny=y+2-i;
		if(nx>n||ny>n||~f[nx][ny])continue;
		f[nx][ny]=(!query(x,y,nx,ny))^f[x][y];
		dfs(nx,ny);
	}
}
int sx,sy,tx,ty;
inline void solve(){
	bool t=f[sx][sy]^(!query(sx,sy,tx,ty))^f[tx][ty];
	cout<<"!"<<'\n';
	for(ri i=1;i<=n;++i,cout<<'\n')for(ri j=1;j<=n;++j){
		if((i+j)&1)cout<<(f[i][j]^t);
		else cout<<f[i][j];
	}
	cout<<endl;
	exit(0);
}
void Dfs(int x,int y,int stp,int sum){
	int lim=n;
	if(x>lim||y>lim)return;
	if(stp==4){
		tx=x,ty=y;
		if(!sum)solve();
		return;
	}
	Dfs(x+1,y,stp+1,sum^f[x+1][y]);
	Dfs(x,y+1,stp+1,sum^f[x][y+1]);
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	memset(f,-1,sizeof(f));
	n=read();
	f[1][1]=1,f[n][n]=0,f[1][2]=0;
	dfs(1,1);
	dfs(1,2);
	f[2][1]=f[2][3]^(!query(2,1,2,3));
	dfs(2,1);
	for(ri i=1;i<=n;++i)for(ri j=1;j<=n;++j)sx=i,sy=j,Dfs(i,j,1,f[i][j]);
	return 0;
}