#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,s,t;
vector<int>go[1100],A[1100],B[1100];
int u[1100],v[1100],id[110][110],g[1100],bo[1100],re[110][110],len;
struct bian{
	int next,point,f;
}b[1000000];
const int inf=1e9;
int p[110],dst[110],x[110],pd[110];
void ade(int k1,int k2,int k3)
{
    len++; b[len].point=k2; b[len].next=p[k1]; b[len].f=k3; p[k1]=len;
}
void add(int k1,int k2,int k3)
{
	//cout<<"ad "<<k1<<" "<<k2<<" "<<k3<<endl;
    ade(k1,k2,k3); ade(k2,k1,0);
}
bool bfs()
{
    int head=1,now=0,i,j;
    memset(dst,0xff,sizeof dst);
    memset(pd,0x00,sizeof pd);
    x[1]=s; pd[s]=1; dst[s]=0;
    while (head>now)
    {
        now++; i=p[x[now]];
        while (i!=-1)
        {
            j=b[i].point;
            if ((b[i].f)&&(!pd[j]))
            {
                pd[j]=1; dst[j]=dst[x[now]]+1;
                if (j==t)
                {
                    return 1;
                }
                head++; x[head]=j;
            }
            i=b[i].next;
        }
    }
    return pd[t];
}
int min(int k1,int k2)
{
    if (k1<k2)
    {
        return k1;
    }
    else
    {
        return k2;
    }
}
int change(int k1,int k2)
{
    if ((k1==t)||(k2==0))
    {
        return k2;
    }
    int num=0,k,i,j;
    i=p[k1];
    while (i!=-1)
    {
        j=b[i].point;
        if ((b[i].f)&&(dst[k1]+1==dst[j]))
        {
            k=change(j,min(k2,b[i].f));
            k2=k2-k; num+=k;
            b[i].f=b[i].f-k; b[i^1].f+=k;
            if (k2==0)
            {
                break;
            }
        }
        i=b[i].next;
    }
    if (!num)
    {
        dst[k1]=-1;
    }
    return num;
}
int dinic()
{
    int num=0;
    while (bfs())
    {
        num+=change(s,inf);
    }
    return num;
}
void dfs1(int k1){
	bo[k1]=1; A[k1].push_back(k1);
	for (int i=0;i<go[k1].size();i++){
		int j=go[k1][i];
		if (bo[j]==0){
			A[j]=A[k1]; dfs1(j);
		}
	}
}
void dfs2(int k1){
	bo[k1]=1; B[k1].push_back(k1);
	for (int i=0;i<go[k1].size();i++){
		int j=go[k1][i];
		if (bo[j]==0){
			B[j]=B[k1]; dfs2(j);
		}
	}
}
int f[1100],ansf[1100];
void addone(int u,int v){
	for (int i=1;i<A[u].size();i++){
		int k1=A[u][i-1],k2=A[u][i];
		f[id[k1][k2]]++;
	}
	for (int i=1;i<B[v].size();i++){
		int k1=B[v][i],k2=B[v][i-1];
		f[id[k1][k2]]++;
	}
	f[id[u][v]]++;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for (int i=1;i<=m;i++) scanf("%d%d%d",&u[i],&v[i],&g[i]),id[u[i]][v[i]]=i;
	for (int i=1;i<=m;i++) if (g[i]) go[u[i]].push_back(v[i]);
	dfs1(s);
	for (int i=1;i<=n;i++) bo[i]=0,go[i].clear();
	for (int i=1;i<=m;i++)
		if (g[i]) go[v[i]].push_back(u[i]);
	dfs2(t);
	len=-1; memset(p,0xff,sizeof p);
	memset(re,0x00,sizeof re);
	for (int i=1;i<=m;i++)
		if (g[i]==0) re[u[i]][v[i]]=1;
		else re[v[i]][u[i]]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n;k++)
				re[j][k]|=(re[j][i]&re[i][k]);
	for (int i=1;i<=m;i++)
		if (g[i]==1) add(u[i],v[i],1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (re[i][j]) add(i,j,inf);
	int ans=dinic();
	for (int i=1;i<=m;i++)
		if (pd[u[i]]&&pd[v[i]]==0&&g[i]) ansf[i]=1;
	for (int i=1;i<=m;i++)
		if (g[i])
			addone(u[i],v[i]);
	printf("%d\n",ans);
	for (int i=1;i<=m;i++)
		printf("%d %d\n",f[i],f[i]+1-ansf[i]);
	return 0;
}