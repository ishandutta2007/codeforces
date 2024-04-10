// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n,t;
int a[N][N],dfn[N],low[N],ins[N];
void tarjan(int u){
    ins[u]=1;
    dfn[u]=low[u]=++t;
    for(int i=0;i<n;++i){
        if(a[u][i]){
            if(!dfn[i]){
                tarjan(i);
                low[u]=min(low[u],low[i]);
            }else if(ins[i]){
                low[u]=min(low[u],dfn[i]);
            }
        }
    }
    if(dfn[u]==low[u]){
        puts(t==n&&!u?"YES":"NO");
        exit(0);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&a[i][j]);
        }
    }
    tarjan(0);
    return 0;
}