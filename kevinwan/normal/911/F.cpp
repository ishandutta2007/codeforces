#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const ll mod=1e9+7;
const int mn=2e5+10;
vector<int>g[mn];
int dep[mn];
bool dia[mn];
void dfs1(int x,int p){
    for(int y:g[x])if(y!=p)dep[y]=dep[x]+1,dfs1(y,x);
}
int mo1,mo2;
ll ans;
vector<pii>v;
void dfs2(int x,int p){
    if(x==mo2){dia[x]=1;return;}
    for(int y:g[x])if(y!=p)dfs2(y,x),dia[x]|=dia[y];
    if(dia[x]) {
        v.push_back({mo2, x});
        ans += dep[mo2] - dep[x];
    }
}
void dfs3(int x,int p,int o){
    if(!dia[x]){
        if(dep[o]>dep[mo2]-dep[o]){
            v.push_back({mo1,x});
            ans+=dep[x];
        }
        else{
            v.push_back({mo2,x});
            ans+=dep[x]-dep[o]*2+dep[mo2];
        }
    }
    for(int y:g[x])if(y!=p){
        if(dia[y])dfs3(y,x,y);
        else dfs3(y,x,o);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1,0);
    mo1=1;
    for(int i=2;i<=n;i++)if(dep[i]>dep[mo1])mo1=i;
    dep[mo1]=0;
    dfs1(mo1,0);
    mo2=1;
    for(int i=2;i<=n;i++)if(dep[i]>dep[mo2])mo2=i;
    dfs2(mo1,0);
    dfs3(mo1,0,mo1);
    printf("%lld\n",ans);
    reverse(v.begin(),v.end());
    for(pii p:v)printf("%d %d %d\n",p.first,p.second,p.second);
}