#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define pii pair<int,int>
#define fi first
#define se second
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const int N=1010;
int n,m,a[N][N],col[N][N],cnt,res[N*N],cl,rs;
vector<pii>tot[N*N];
int vis[N][N],ans;
void dfs(int x,int y,int v){
	if(x>0&&y>0&&x<=n&&y<=m&&a[x][y]==v&&!col[x][y]){
		col[x][y]=cnt;
		dfs(x+1,y,v),dfs(x-1,y,v);
		dfs(x,y+1,v),dfs(x,y-1,v);
	}
}
void dfs2(int x,int y,int v){
	if(x>0&&y>0&&x<=n&&y<=m&&a[x][y]==v&&!col[x][y]){
		col[x][y]=cnt;
		dfs2(x+1,y,v),dfs2(x-1,y,v);
		dfs2(x,y+1,v),dfs2(x,y-1,v);
		dfs2(x+1,y+1,v),dfs2(x-1,y-1,v);
		dfs2(x-1,y+1,v),dfs2(x+1,y-1,v);
	}
}
void check(int x,int y){
	if(x>0&&y>0&&x<=n&&y<=m){
		if(a[x][y]==1){
			if(!vis[x][y])vis[x][y]=1,++rs;
			if(!cl)cl=col[x][y];
			else if(cl!=col[x][y])rs=-1919810;
		}
	}
	else rs=-1919810;
}
void chec(int x,int y){
	if(x>0&&y>0&&x<=n&&y<=m)vis[x][y]=0;
}
void heck(int x,int y){
	if(x>0&&y>0&&x<=n&&y<=m){
		if(vis[x][y]==1&&vis[x+1][y]+vis[x-1][y]+vis[x][y+1]+vis[x][y-1]!=2)rs=-1919810;
	}
}
signed main(){
	read(n,m);
	for(rgi i=1;i<=n;++i){
		for(rgi j=1;j<=m;++j)scanf("%1d",&a[i][j]);
	}
	for(rgi i=1;i<=n;++i){
		for(rgi j=1;j<=m;++j){
			if(a[i][j]==1&&a[i][j+1]==1&&a[i+1][j]==1&&a[i+1][j+1]==1)ans=4;
			if(!col[i][j]){
				++cnt;
				if(a[i][j])dfs(i,j,a[i][j]);
				else dfs2(i,j,a[i][j]);
			}
		}
	}
	for(rgi x=1;x<=n;++x){
		for(rgi y=1;y<=m;++y){
			tot[col[x][y]].push_back(pii(x,y));
		}
	}
	for(rgi i=1;i<=cnt;++i){
		rs=cl=0;
		for(pii k:tot[i]){
			int x=k.fi,y=k.se;
			if(a[x][y])break;
			check(x+1,y);
			check(x-1,y);
			check(x,y+1);
			check(x,y-1);
			check(x+1,y-1);
			check(x+1,y+1);
			check(x-1,y-1);
			check(x-1,y+1);
		}
		for(pii k:tot[i]){
			int x=k.fi,y=k.se;
			if(a[x][y])break;
			heck(x+1,y);
			heck(x-1,y);
			heck(x,y+1);
			heck(x,y-1);
			heck(x+1,y-1);
			heck(x+1,y+1);
			heck(x-1,y-1);
			heck(x-1,y+1);
		}
		for(pii k:tot[i]){
			int x=k.fi,y=k.se;
			if(a[x][y])break;
			chec(x+1,y);
			chec(x-1,y);
			chec(x,y+1);
			chec(x,y-1);
			chec(x+1,y-1);
			chec(x+1,y+1);
			chec(x-1,y-1);
			chec(x-1,y+1);
		}
		ans=max(ans,rs);
	}
	write(ans);
	return 0;
}