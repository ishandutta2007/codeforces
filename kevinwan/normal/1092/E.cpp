#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=1e6+10;
const ll mod=998244353;
vector<int>g[mn];
int cc[mn],down[mn],down2[mn],up[mn];
int ct=0;
void dfs1(int x,int p){
    cc[x]=ct;
    for(int y:g[x])if(y!=p){
        dfs1(y,x);
        if(down[y]+1>down[x])down2[x]=down[x],down[x]=down[y]+1;
        else if(down[y]+1>down2[x])down2[x]=down2[x]=down[y]+1;
    }
}
void dfs2(int x,int p){
    for(int y:g[x])if(y!=p){
        up[y]=up[x]+1;
        if(down[y]+1==down[x])up[y]=max(up[y],down2[x]+1);
        else up[y]=max(up[y],down[x]+1);
        dfs2(y,x);
    }
}
int mo;
int mi[mn],pos[mn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++)if(!cc[i])++ct,dfs1(i,0),dfs2(i,0);
    for(int i=1;i<=n;i++)mo=max(mo,max(down[i],up[i]));
    memset(mi,0x3f,sizeof(mi));
    for(int i=1;i<=n;i++){
        if(max(down[i],up[i])<mi[cc[i]])mi[cc[i]]=max(down[i],up[i]),pos[cc[i]]=i;
    }
    vector<int>o(ct);
    iota(o.begin(),o.end(),1);
    sort(o.begin(),o.end(),[](int a,int b){return mi[a]>mi[b];});
    if(o.size()==1)printf("%d\n",mo);
    else if(o.size()==2)printf("%d\n",max(mo,mi[o[0]]+mi[o[1]]+1));
    else printf("%d\n",max(max(mo,mi[o[0]]+mi[o[1]]+1),mi[o[1]]+mi[o[2]]+2));
    for(int i=1;i<o.size();i++){
        printf("%d %d\n",pos[o[i]],pos[o[0]]);
    }
}