#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int mn=5e5+10;
vector<int>g[mn];
set<pii>*u[mn];
int dep[mn],s[mn];
void dfs(int x,int p){
    int bes=0;
    s[x]=1;
    for(int y:g[x]){
        if(y==p)continue;
        dep[y]=dep[x]+1;
        dfs(y,x);
        s[x]+=s[y];
        if(s[y]>s[bes])bes=y;
    }
    if(!bes)u[x]->insert({dep[x],dep[x]+1}),u[x]->insert({-1000,-1000});
    else if(x!=1){
        u[x]=u[bes];
        for (int y:g[x]){
            if(y==p||y==bes)continue;
            for(auto&p:*u[y]){
                for(int i=p.first;i<p.second;i++){
                    auto nxt=u[x]->upper_bound({i,0x3f3f3f3f});
                    auto it=--nxt;
                    ++nxt;
                    if(it->second<i){
                        if(nxt!=u[x]->end()&&nxt->first==i+1){
                            u[x]->insert({nxt->first-1,nxt->second});
                            u[x]->erase(nxt);
                        }
                        else u[x]->insert({i,i+1});
                        continue;
                    }
                    if(nxt!=u[x]->end()&&it->second+1==nxt->first){
                        u[x]->insert({it->first,nxt->second});
                        u[x]->erase(it);
                        u[x]->erase(nxt);
                    }
                    else{
                        u[x]->insert({it->first,it->second+1});
                        u[x]->erase(it);
                    }
                }
            }
        }
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
    for(int i=0;i<=n;i++)u[i]=new set<pii>();
    dfs(1,0);
    int ans=0;
    for(int y:g[1])ans=max(ans,(--u[y]->end())->second-1);
    printf("%d",ans);
}