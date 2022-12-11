#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=5001,mod=998244353;
int n,k;
int f[maxn][maxn],g[maxn],mlen[maxn],ans;
vector <int> v[maxn];
inline int read(){
    int res=0;
    char ch=getchar(),ch1=ch;
    while(!isdigit(ch))ch1=ch,ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return ch1=='-'?-res:res;
}
int qmod(int x){
    return x>=mod?x-mod:x;
}
void dfs(int p,int fa){
    f[p][0]=1;
    for(int i=0,y;i<v[p].size();++i){
        y=v[p][i];
        if(y==fa)continue;
        dfs(y,p);
        for(int j=0;j<=mlen[p];++j)
            for(int t=0,to;t<=mlen[y];++t){
                if(j+t+1<=k){
                    to=max(j,t+1);
                    g[to]=qmod(g[to]+1ll*f[p][j]*f[y][t]%mod);
                }
                to=j;
                g[to]=qmod(g[to]+1ll*f[p][j]*f[y][t]%mod);
            }
        mlen[p]=min(max(mlen[p],mlen[y]+1),k);
        for(int j=0;j<=mlen[p];++j)
            f[p][j]=g[j],g[j]=0;
    }
}
int main(){
    n=read();k=read();
    for(int i=1,x,y;i<n;++i){
        x=read();y=read();
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    for(int i=0;i<=k;++i)
        ans=qmod(ans+f[1][i]);
    printf("%d\n",ans);
    return 0;
}