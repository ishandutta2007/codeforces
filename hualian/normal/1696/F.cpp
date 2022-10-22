#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=1e4+110,M=110;
int fa[N],n;
#define pi pair<int,int>
#define fi first
#define se second
vector<pi> g[N];
char ch[M];
int id[M][M],vis[N];
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
vector<int> to[M];
int d[M];
void dfs(int u,int f){
	for(auto v:to[u])if(v!=f){
		d[v]=d[u]+1,dfs(v,u);
	}
}
int dis[M][M];
bool eq[M][M][M];
bool check(int x){
	if(g[x].size()!=n-1)return 0;
	for(auto e:g[x])to[e.fi].push_back(e.se),to[e.se].push_back(e.fi);
//	for(auto e:g[x])printf("%d %d\n",e.fi,e.se); 
	For(u,1,n){
		memset(d,0,sizeof d); 
		dfs(u,0);
		For(v,1,n)dis[u][v]=d[v];
	}
	For(i,1,n)For(j,i+1,n)For(k,1,n){
		if(eq[i][j][k]){
			if(dis[i][k]!=dis[j][k])return 0;
		}else{
			if(dis[i][k]==dis[j][k])return 0;
		}
	}
	return 1;
}
void merge(int x,int y){
	fa[get(x)]=get(y);
}int cc[M];
signed main(){
	int T=read();while(T--){
		n=read();int idx=0;
		For(i,1,n)For(j,i+1,n)id[i][j]=id[j][i]=++idx;
//		For(i,1,n)id[i][i]=++idx; 
		For(i,1,idx)vis[i]=0,fa[i]=i,g[i].clear();
		For(i,1,n)to[i].clear();
		int ban=0;
		For(i,1,n-1){
			For(j,1,n-i){
				scanf("%s",ch+1);
				For(k,1,n){
					int x=i,y=i+j,z=k;
					if(ch[k]=='1'){
						//(x,z)==(y,z)
						merge(id[x][z],id[y][z]);
						if(x==z&&y!=z||y==z&&x!=z)ban=1;
//						printf("(%d,%d) - (%d,%d)\n",x,z,y,z); 
					}eq[x][y][z]=ch[k]=='1';
					
				}
			}
		}
		if(ban){puts("No");continue;} 
		For(i,1,n)For(j,i+1,n)g[get(id[i][j])].push_back(pi(i,j));
		int fl=0;
		For(i,1,idx)if(!vis[get(i)]){
			int x=get(i);vis[x]=1;
			For(j,1,n)cc[j]=0;
			for(auto e:g[x])
				cc[e.fi]=1,cc[e.se]=1;
			int s=0;For(j,1,n)s+=cc[j];
			if(s!=n||g[x].size()!=n-1)continue;
			if(check(x)){
				fl=1;
				puts("Yes");
				for(auto e:g[x])printf("%d %d\n",e.fi,e.se);
			}
//			break;
       For(i,1,n)to[i].clear();
		}if(!fl)puts("No");
	}
	return 0;
}