#include<bits/stdc++.h>
using namespace std;
const int dx[8]={1,-1,0, 0,-1,1,-1, 1};
const int dy[8]={0, 0,1,-1,-1,1, 1,-1};
int T,r,c,n,fa[21000000],rk[21000000],num[21000000],lim;
bool vis[3100][6100];
char Getchar(){
	static char now[1<<20],*S,*T;
	if (T==S){
		T=(S=now)+fread(now,1,1<<20,stdin);
		if (T==S) return EOF;
	}
	return *S++;
}
int read(){
	int x=0,f=1;
	char ch=Getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=Getchar();
	}
	while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
	return x*f;
}
int findset(int x){
	if (x!=fa[x]) fa[x]=findset(fa[x]);
	return fa[x];
}
void Union2(int x,int y){
	x=findset(x); y=findset(y);
	if (rk[x]<rk[y]) fa[x]=y,rk[y]+=rk[x];
	else fa[y]=x,rk[x]+=rk[y];
}
int hs(int x,int y){
	return (x-1)*2*c+y;
}
void Union(int x,int y){
	vis[x][y]=true;
	int nx,ny;
	for (int k=0;k<8;k++){
		nx=x+dx[k]; ny=y+dy[k];
		if (ny<1) ny+=c*2;
		if (ny>c*2) ny-=c*2; 
		if (nx<1||nx>r) continue;
		if (vis[nx][ny]) Union2(hs(x,y),hs(nx,ny));
	}
}
bool check(int t,int x,int y){
	int nx,ny,tmp; //bool f0=false,f1=false;
	for (int k=0;k<8;k++){
		nx=x+dx[k]; ny=y+dy[k];
		if (ny<1) ny+=c*2;
		if (ny>c*2) ny-=c*2; 
		if (nx<1||nx>r) continue;
		if (vis[nx][ny]){
			tmp=findset(hs(nx,ny));
//			if (tmp==findset(0)) f0=true;
//			else if (tmp==findset(lim)) f1=true;
//			else 
			num[tmp]=t;
		}
	}
//	if (f0&&f1) return false;
	y+=c; //bool g0=false,g1=false;
	bool flag=false;
	for (int k=0;k<8;k++){
		nx=x+dx[k]; ny=y+dy[k];
		if (nx<1||nx>r||ny<1||ny>c*2) continue;
		if (vis[nx][ny]){
			tmp=findset(hs(nx,ny));
//			if (tmp==findset(0)) g0=true;
//			else if (tmp==findset(lim)) g1=true;
//			else 
			if (num[tmp]==t) flag=true;
		}
	}
//	if (g0&&g1) return false;
	if (flag) return false;
	return true;
}
int main(){
//	freopen("reclaim.in","r",stdin);
//	freopen("reclaim.out","w",stdout);
	T=1;
	while (T--){
		r=read(); c=read(); n=read();
		lim=hs(r,2*c)+1;
		for (int i=1;i<=r;i++)
			for (int j=1;j<=2*c;j++)
				vis[i][j]=false;
		for (int i=0;i<=lim;i++){
			fa[i]=i; rk[i]=1;
			num[i]=0;
		}
		int x,y,ans=0;
		for (int i=1;i<=n;i++){
			x=read(); y=read();
			if (c!=1){
				if (check(i,x,y)){
					Union(x,y); ans++;
					Union(x,y+c);
					assert(findset(hs(x,y))!=findset(hs(x,y+c)));
				}// else printf("%d\n",i);
			}
		}
		if (c==1) puts("0");
		else printf("%d\n",ans);
	}
	return 0;
}