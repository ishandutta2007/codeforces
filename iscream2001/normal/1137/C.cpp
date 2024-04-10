#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
#define mod 985003
#define ept 1e-10
#define LL long long
#define inf 1000000000
using namespace std;
inline int Read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const int N=1e5+50;
bool vv[N][55];
int pos[N][55];
int n,m,D,Ecnt=0,dfn=0,top=0,blo=0;
int hed[N],DFN[N],low[N],g[N],q[N],du[N];

int a[N*55];
int f[N*55];
struct edge{
    int r,nxt;
}e[N];
void insert(int u,int v){
    e[++Ecnt].r=v;e[Ecnt].nxt=hed[u];hed[u]=Ecnt;
}
void tarjan(int x){
    DFN[x]=low[x]=++dfn;
    q[++top]=x;
    for(int i=hed[x];i;i=e[i].nxt)
        if(!DFN[e[i].r]){
            tarjan(e[i].r);
            low[x]=min(low[x],low[e[i].r]);
        }
        else if(!g[e[i].r]) low[x]=min(low[x],DFN[e[i].r]);
    if(DFN[x]==low[x]){
        blo++;
        while(q[top]!=x&&top){
            g[q[top]]=blo;top--;
        }
        g[q[top]]=blo;top--;
    }
}
int ppp=0;
char s[55];
bool cmp(int A,int B){return g[A]<g[B];}
int sta[N];
bool vis[N][55];
int now[N];
void dfs(int x,int y){
	//cout<<x<<" "<<y<<" "<<ppp<<" "<<a[ppp]<<endl;
	pos[x][y]=ppp;
	vis[x][y]=1;
	if(now[x]!=ppp&&vv[x][y]){
		now[x]=ppp;
		++a[ppp];
	}
	int z;
	if(y<D) z=y+1;
	else z=1;
	for(int i=hed[x];i;i=e[i].nxt)
		if(vis[e[i].r][z]==0&&g[x]==g[e[i].r]) dfs(e[i].r,z);
	return;
}
int main(){
	scanf("%d%d%d",&n,&m,&D);
	int u,v;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		insert(u,v);
	}
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		for(int j=1;j<=D;++j){
			vv[i][j]=s[j]-'0';
		}
	}
	for(int i=1;i<=n;++i){
		if(!DFN[i]) tarjan(i);
		sta[i]=i;
	}
	//cout<<blo<<endl;
	sort(sta+1,sta+1+n,cmp);
	//for(int i=1;i<=n;++i) cout<<sta[i]<<" ";cout<<endl;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=D;++j){
			if(!vis[i][j]){
				++ppp;
				dfs(i,j);
			}
		}
	}
	for(int i=1;i<=ppp;++i) f[i]=a[i];
	int z,x;
	for(int i=1;i<=n;++i){
		x=sta[i];
		for(int j=1;j<=D;++j){
			if(j<D) z=j+1;
			else z=1;
			for(int k=hed[x];k;k=e[k].nxt){
				if(g[x]!=g[e[k].r]){
					f[pos[x][j]]=max(f[pos[x][j]],f[pos[e[k].r][z]]+a[pos[x][j]]);
					//cout<<x<<" "<<pos[x][j]<<" "<<f[pos[x][j]]<<" "<<a[pos[x][j]]<<endl;
				}
			}
		}
	}
	printf("%d\n",f[1]);
	return 0;
}