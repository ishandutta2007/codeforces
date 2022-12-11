#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<bitset>
using namespace std;
const int maxn=2e5+5,maxm=0,mod=0;
int n,m;
int b[maxn],ans[maxn];
int deg[maxn];
bool vis[maxn];
inline int read(){
    int res=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return res;
}
int dfs(int p){
    vis[p]=true;
    if(!vis[b[p]])return dfs(b[p]);
    else return p;
}
void proc(){
    n=read();
    for(int i=1;i<=n;++i)
        deg[i]=vis[i]=0;
    for(int i=1;i<=n;++i){
        b[i]=read();
        ++deg[b[i]];
        ans[i]=b[i];
    }
    int frt=0,fed=0,cnt=0;
    for(int i=1;i<=n;++i)
        if(!deg[i]){
            int x=dfs(i);
            if(!x)continue;
            if(!frt){
                frt=i;fed=x;
            }
            else{
                ans[fed]=i;
                fed=x;
            }
            ++cnt;
        }
    if(frt)ans[fed]=frt;
    printf("%d\n",n-cnt);
    for(int i=1;i<=n;++i)
        printf("%d ",ans[i]);
    puts("");
}
int main(){
    int T=read();
    while(T--)proc();
    return 0;
}