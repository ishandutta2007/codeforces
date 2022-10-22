#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=4e5+10;
int n;
vector<int>g[mn];
int s[mn],ans[mn];
pair<pii,pii> bes[mn];
void add(pair<pii,pii>&p,pii x){
    if(x.first>p.first.first){
        if(p.first.second!=x.second)p.second=p.first;
        p.first=x;
    }
    else if(x.first>p.second.first&&p.first.second!=x.second)p.second=x;
}
void dfs1(int x,int p){
    s[x]=1;
    for(int y:g[x]){
        if(y==p)continue;
        dfs1(y,x);
        s[x]+=s[y];
        if(s[y]<=n/2){
            add(bes[x],{s[y],y});
        }
        if(bes[y].first.second!=x)add(bes[x],{bes[y].first.first,y});
        if(bes[y].second.second!=x)add(bes[x],{bes[y].second.first,y});
    }
    if(n-s[x]<=n/2)add(bes[x],{n-s[x],p});
}
void dfs2(int x,int p){
    if(bes[p].first.second!=x)add(bes[x],{bes[p].first.first,p});
    if(bes[p].second.second!=x)add(bes[x],{bes[p].second.first,p});
    for(int y:g[x])if(y!=p)dfs2(y,x);
    bool gud=1;
    for(int y:g[x]){
        int num;
        if(y==p)num=n-s[x];
        else num=s[y];
        if(bes[y].first.second==x)num-=bes[y].second.first;
        else num-=bes[y].first.first;
        if(num>n/2)gud=0;
    }
    ans[x]=gud;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}