#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
#include<cmath>

int n,m;
struct edge{
    int v,next,vis;
}e[1000005];int g[500005],etot;
void ae(int u,int v){
    e[etot].v=v;e[etot].next=g[u];g[u]=etot++;
}
int U[1000000],V[1000000],val[1000000]={0};
int stk[500005],cur[500005],ine[500005];int top;
int seq[1000000],vis[1000000]={0},ind;int lab[1000000]={0};
int ans[1000005];int anslen=0;
int vv[100005];
void dfs2(int rt){
    top=0;
    stk[++top]=rt;ine[top]=-1;
    while(top){
        int u=stk[top];
	vv[u]=1;
        while(~g[u] && e[g[u]].vis)g[u]=e[g[u]].next;
        if(~g[u]){
            e[g[u]].vis=e[g[u]^1].vis=1;
            int v=e[g[u]].v;
            ine[top+1]=g[u];
            g[u]=e[g[u]].next;
            stk[++top]=v;
        }else{
            if(~ine[top]){
                ans[++anslen]=ine[top];
            }
            top--;
        }
    }
}
int deg[100005];
int ls[100005];int ltot=0;
int main()
{
	memset(g,-1,sizeof(g));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ae(x,y);
		ae(y,x);
		deg[x]++;deg[y]++;
	}
	for (int i=1;i<=n;i++)if(deg[i]&1)ls[++ltot]=i;
	for (int i=1;i<=ltot;i+=2)ae(ls[i],ls[i+1]),ae(ls[i+1],ls[i]);
	if((ltot/2+m)&1)ae(1,1),ae(1,1);
	for (int i=1;i<=n;i++)if(!vv[i])dfs2(i);
	printf("%d\n",anslen);
	for (int i=1;i<=anslen;i++){
		printf("%d %d\n",e[::ans[i]^(i&1)].v,e[::ans[i]^!(i&1)].v);
	}
	return 0;
}