#include<bits/stdc++.h>
using namespace std;
int n,m,lst[4100000],deg[4100000],ans; bool vis[4100000];
int edgenum=1,vet[21000000],Next[21000000],Head[4100000];
char Getchar(){
    static char now[1<<20],*S,*T;
    if (T==S){
        T=(S=now)+fread(now,1,1<<20,stdin);
        if (T==S) return EOF;
    }
    return *S++;
}
int read(){
    int x=0,f=1;
    char ch=Getchar();
    while (ch<'0'||ch>'9'){
        if (ch=='-') f=-1;
        ch=Getchar();
    }
    while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
    return x*f;
}
void addedge(int u,int v){
    vet[++edgenum]=v;
    Next[edgenum]=Head[u];
    Head[u]=edgenum;
}
void dfs(int u){
    int v; vis[u]=true;
    for (int e=Head[u];e;e=Next[e]){
        v=vet[e]; if (e==lst[u]) continue;
        if (!lst[v]) lst[v]=(e^1),dfs(v);
        else
            if (vis[v]){
                int w=u,tot=0;
                while (w!=v) tot+=(deg[w]>2),w=vet[lst[w]];
                tot+=(deg[v]>2);
                if (tot<2) ans++;
            }
    }
    vis[u]=false;
}
int main(){
    n=read(); m=read(); int u,v;
    for (int i=1;i<=m;i++){
        u=read(); v=read();
        deg[u]++; deg[v]++;
        addedge(u,v); addedge(v,u);
    }
    for (int i=1;i<=n;i++) ans+=(deg[i]&1);
    ans>>=1; dfs(1);
    cout<<ans<<' '<<m<<'\n';
    return 0;
}