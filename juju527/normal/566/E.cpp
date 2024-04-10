#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
bitset<maxn>f[maxn],g[maxn],to[maxn],h[maxn],S,T;
bool leaf[maxn];
bool vis[maxn][maxn];
struct Edge{
    int to,nxt;
}e[2*maxn];
int cnt;
int head[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add(int u,int v){
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt++;
    return ;
}
void dfs(int x,int fa){
    if(fa)g[x][fa]=1;
    int num=0;
    for(int i=head[x];i!=-1;i=e[i].nxt){
        int tmp=e[i].to;
        if(tmp==fa)continue;
        printf("%d %d\n",x,tmp);
        dfs(tmp,x);
        g[x][tmp]=1;
    	num++;
	}
    if(!num)leaf[x];
    return ;
}
int main(){
    int n;
    n=read();
    for(int i=1;i<=n;i++){
        int k;
        k=read();
        S[i]=1;
        for(int j=1;j<=k;j++)f[i][read()]=1;
    }
    if(n==2){puts("1 2");return 0;}
    int rt;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            bitset<maxn>b=f[i]&f[j];
            if(b.count()==2){
                int u=b._Find_first(),v=b._Find_next(u);
                if(!vis[u][v]){
                	vis[u][v]=1;
					add(u,v);
					add(v,u);
				}
                T[u]=T[v]=1;
                rt=u;
            }
        }
    }
    if(T.count()==0){
        rt=1;
        for(int i=1;i<=n;i++)if(i!=rt)printf("%d %d\n",rt,i);
        return 0;
    }
    if(T.count()==2){
        int u=T._Find_first(),v=T._Find_next(u);
        bitset<maxn>p;
        bool flag=0;
        printf("%d %d\n",u,v);
        for(int i=1;i<=n;i++){
            if(f[i]==S)continue;
            if(flag&&p==f[i])continue;
            p=f[i];
            if(!flag){
                for(int j=1;j<=n;j++){
                    if(j==u||j==v)continue;
                    if(f[i][j])printf("%d %d\n",u,j);
                }
            }
            else{
                for(int j=1;j<=n;j++){
                    if(j==u||j==v)continue;
                    if(f[i][j])printf("%d %d\n",v,j);
                }
                break;
            }
            flag=1;
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
    	if(T[i])continue;
    	int num=n;
    	for(int j=1;j<=n;j++){
    		if(f[j][i]==1&&f[j].count()<num){
    			h[i]=f[j];
    			num=f[j].count();
			}
		}
	}
    dfs(rt,0);
    for(int i=1;i<=n;i++)if(T[i])g[i][i]=1;
    for(int i=1;i<=n;i++){
    	if(T[i])continue;
        for(int x=1;x<=n;x++){
            if(!T[x])continue;
			if((h[i]&T)==g[x])
                to[x]|=((h[i]|T)^T);
        }
    }
    for(int i=1;i<=n;i++){
        int cur=to[i].count();
        if(!T[i]||!cur)continue;
        int x=to[i]._Find_first();cur--;
        printf("%d %d\n",i,x);
        while(cur){
            x=to[i]._Find_next(x);
	        printf("%d %d\n",i,x);
            cur--;
        }
    }
    return 0;
}