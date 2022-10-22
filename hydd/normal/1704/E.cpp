#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int T,n,m,a[1100],p[1100],ans;
int head,tail,que[1100],deg[1100];
vector<int> vec[1100];
void topo_sort(){
    head=1; tail=0;
    for (int i=1;i<=n;i++)
        if (!deg[i]) que[++tail]=i;
    while (head<=tail){
        int u=que[head++];
        for (int v:vec[u])
            if (!(--deg[v])) que[++tail]=v;
    }
    for (int i=1;i<=n;i++) p[i]=que[i];
}
void update(){
    bool f=false;
    for (int i=n;i>=1;i--){
        int u=p[i]; if (!a[u]) continue;
        a[u]--; f=true;
        for (int v:vec[u]) a[v]++;
    }
    ans+=f;
}
int calc(){
    for (int i=1;i<=n;i++){
        int u=p[i]; a[u]%=Mod;
        for (int v:vec[u]) a[v]=(a[v]+a[u])%Mod;
    }
    return a[p[n]];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>T;
    while (T--){
        cin>>n>>m;
        for (int i=1;i<=n;i++) cin>>a[i];
        int u,v;
        for (int i=1;i<=m;i++){
            cin>>u>>v; deg[v]++;
            vec[u].push_back(v);
        }
        topo_sort(); ans=0;
        for (int i=1;i<=n;i++) update();
        cout<<(ans+calc())%Mod<<'\n';
        for (int i=1;i<=n;i++) vec[i].clear(),deg[i]=0;
    }
    return 0;
}