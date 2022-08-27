#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;

int n;
int deg[100005],si[100005];
int vis[100005];
int qu[100005];int p=0,q=0;
int U[100005],V[100005],etot=0;
int main()
{
    scanf("%d",&n);
    int m=0;
    for (int i=0;i<n;i++){
        scanf("%d%d",&deg[i],&si[i]);
        if(deg[i]==1)qu[q++]=i,vis[i]=1;
    }
    while(p!=q){
        int u=qu[p++];
        if(deg[u]==0)continue;
        int v=si[u];
        U[++etot]=u;V[etot]=v;
        deg[u]--;deg[v]--;
        si[v]^=u;
        if(deg[v]==1)qu[q++]=v;
    }
    printf("%d\n",etot);
    for (int i=1;i<=etot;i++)printf("%d %d\n",U[i],V[i]);
    return 0;
}