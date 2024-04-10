#include <bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=1e3+5;
const int INF=1e9;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void pls(LL &x,LL y){
    x+=y;if(x>=P)x-=P;
}

int h,w,Q,cnt;
char s[N];
int a[N][N];
int num[N][N];
int fa[N*N],sz[N*N],blo[N*N];
bool visL[N*N],visR[N*N];
int K;
struct Node{
	int x,y;
}p[15];

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int tp;
int q[N*N];

map<int,int> mp[N*N];
int gettop(int x){
	while(fa[x]!=x) x=fa[x];
	return x;
}
void merge(int x,int y){
	int u=gettop(x),v=gettop(y);
	if(u==v) return;
	if(sz[u]>sz[v]) swap(u,v);
	fa[u]=v;sz[v]+=sz[u];q[++tp]=u;
	return;
}
void MAIN(){
	int nx,ny,mx,my,u,v;
	scanf("%d%d%d",&h,&w,&Q);
    for(int i=0;i<=h+1;++i){
    	for(int j=0;j<=w+1;++j){
    		a[i][j]=0;
    		if(i==0&&j>=3) a[i][j]=1;
    		if(j==0&&i>=3) a[i][j]=1;
    		if(i==h+1&&j<=w-2) a[i][j]=1;
    		if(j==w+1&&i<=h-2) a[i][j]=1;
		}
	}
	for(int i=1;i<=h;++i){
		scanf("%s",s+1);
		for(int j=1;j<=w;++j){
			if(s[j]=='#') a[i][j]=1;
			else a[i][j]=0;
		}
	}
	cnt=0;
	for(int i=0;i<=h+1;++i){
		for(int j=0;j<=w+1;++j){
			num[i][j]=++cnt;
			fa[cnt]=cnt;
			sz[cnt]=1;
		}
	}
	tp=0;
	for(int i=0;i<=h+1;++i){
		for(int j=0;j<=w+1;++j){
			if(!a[i][j]) continue;
			for(int xxx=-1;xxx<=1;++xxx){
				for(int yyy=-1;yyy<=1;++yyy){
					nx=i+xxx;
					ny=j+yyy;
					if(nx<0||ny<0||nx>h+1||ny>w+1||a[nx][ny]==0) continue;
					u=find(num[i][j]);
					v=find(num[nx][ny]);
					if(u!=v) fa[v]=u;
				}
			}
		}
	}
	for(int i=0;i<=h+1;++i){
		for(int j=0;j<=w+1;++j){
			u=find(num[i][j]);
			blo[num[i][j]]=fa[num[i][j]];
		}
	}
	for(int i=0;i<=h+1;++i){
		for(int j=0;j<=w+1;++j){
			if(!a[i][j]) continue;
			for(int xxx=-2;xxx<=2;++xxx){
				for(int yyy=-2;yyy<=2;++yyy){
					nx=i+xxx;
					ny=j+yyy;
					if(nx<0||ny<0||nx>h+1||ny>w+1||a[nx][ny]==0) continue;
					u=blo[num[i][j]];
					v=blo[num[nx][ny]];
					if(u==v) continue;
					mp[u][v]=1;
					mp[v][u]=1;
					
					if(v==blo[num[0][w+1]]) visR[u]=1;
					if(u==blo[num[0][w+1]]) visR[v]=1;
					
					if(v==blo[num[h+1][0]]) visL[u]=1;
					if(u==blo[num[h+1][0]]) visL[v]=1;
				}
			}
		}
	}
	while(Q--){
		scanf("%d",&K);
		for(int i=1;i<=K;++i){
			scanf("%d%d",&p[i].x,&p[i].y);
			a[p[i].x][p[i].y]=1;
		}
		bool flag=0;
		if(blo[num[h+1][0]]==blo[num[0][w+1]]) flag=1;
		if(mp[blo[num[h+1][0]]][blo[num[0][w+1]]]) flag=1;
		if(!flag){
			for(int i=1;i<=K;++i){
				for(int xxx=-1;xxx<=1;++xxx){
					for(int yyy=-1;yyy<=1;++yyy){
						nx=p[i].x+xxx;
						ny=p[i].y+yyy;
						if(nx<0||ny<0||nx>h+1||ny>w+1||a[nx][ny]==0) continue;
						merge(num[p[i].x][p[i].y],num[nx][ny]);
					}
				}
			}
			if(gettop(num[h+1][0])==gettop(num[0][w+1])) flag=1;
			for(int i=1;i<=K;++i){
				if(gettop(num[h+1][0])==gettop(num[p[i].x][p[i].y])){
					for(int xxx=-2;xxx<=2;++xxx){
						for(int yyy=-2;yyy<=2;++yyy){
							nx=p[i].x+xxx;
							ny=p[i].y+yyy;
							if(nx<0||ny<0||nx>h+1||ny>w+1||a[nx][ny]==0) continue;
							if(gettop(num[0][w+1])==gettop(num[nx][ny])) flag=1;
						}
					}
				}
				if(gettop(num[0][w+1])==gettop(num[p[i].x][p[i].y])){
					for(int xxx=-2;xxx<=2;++xxx){
						for(int yyy=-2;yyy<=2;++yyy){
							nx=p[i].x+xxx;
							ny=p[i].y+yyy;
							if(nx<0||ny<0||nx>h+1||ny>w+1||a[nx][ny]==0) continue;
							if(gettop(num[h+1][0])==gettop(num[nx][ny])) flag=1;
						}
					}
				}
			}
			for(int i=1;i<=K;++i){
				if(gettop(num[h+1][0])==gettop(num[p[i].x][p[i].y])){
					for(int xxx=-1;xxx<=1;++xxx){
						for(int yyy=-1;yyy<=1;++yyy){
							nx=p[i].x+xxx;
							ny=p[i].y+yyy;
							if(nx<0||ny<0||nx>h+1||ny>w+1||a[nx][ny]==0) continue;
							if(visR[blo[num[nx][ny]]]) flag=1;
						}
					}
				}
				if(gettop(num[0][w+1])==gettop(num[p[i].x][p[i].y])){
					for(int xxx=-1;xxx<=1;++xxx){
						for(int yyy=-1;yyy<=1;++yyy){
							nx=p[i].x+xxx;
							ny=p[i].y+yyy;
							if(nx<0||ny<0||nx>h+1||ny>w+1||a[nx][ny]==0) continue;
							if(visL[blo[num[nx][ny]]]) flag=1;
						}
					}
				}
			}
			for(int i=1;i<=K;++i){
				for(int j=i+1;j<=K;++j){
					if(
					(gettop(num[h+1][0])==gettop(num[p[i].x][p[i].y])
					&&gettop(num[0][w+1])==gettop(num[p[j].x][p[j].y]))
					||
					(gettop(num[h+1][0])==gettop(num[p[j].x][p[j].y])
					&&gettop(num[0][w+1])==gettop(num[p[i].x][p[i].y]))
					){
						for(int xxx=-1;xxx<=1;++xxx){
							for(int yyy=-1;yyy<=1;++yyy){
								for(int xx=-1;xx<=1;++xx){
									for(int yy=-1;yy<=1;++yy){
										nx=p[i].x+xxx;
										ny=p[i].y+yyy;
										mx=p[j].x+xx;
										my=p[j].y+yy;
										if(nx<0||ny<0||nx>h+1||ny>w+1||a[nx][ny]==0) continue;
										if(mx<0||my<0||mx>h+1||my>w+1||a[mx][my]==0) continue;
										if(mp[blo[num[nx][ny]]][blo[num[mx][my]]]) flag=1;
									}
								}
							}
						}
					}
				}
			}
			while(tp>0){
				sz[fa[q[tp]]]-=sz[q[tp]];
				fa[q[tp]]=q[tp];
				tp--;
			}
		}
		if(flag) puts("NO");
		else puts("YES");
		fflush(stdout);
		for(int i=1;i<=K;++i){
			a[p[i].x][p[i].y]=0;
		}
	}
	return;
}

int main(){
    int ttt=1;
    while(ttt--) MAIN();
    return 0;
}