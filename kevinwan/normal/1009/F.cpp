#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int mn=1e6+10;
vector<int>g[mn],ch[mn];
priority_queue<pii>pq[mn];
int ans[mn];
void dfs(int x,int p){
    int bes=0;
    for(int y:g[x]){
        if(y==p)continue;
        dfs(y,x);
        if(ch[y].size()>ch[bes].size())bes=y;
    }
    swap(pq[bes],pq[x]);
    swap(ch[bes],ch[x]);
    for(int y:g[x]){
        if(y==p||y==bes)continue;
        for(int i=1;i<=ch[y].size();i++){
            ch[x][ch[x].size()-i]+=ch[y][ch[y].size()-i];
            pq[x].push({ch[x][ch[x].size()-i],ch[x].size()-i});
        }
    }
    ch[x].push_back(1);
    pq[x].push({1,ch[x].size()-1});
    while(ch[x][pq[x].top().second]!=pq[x].top().first)pq[x].pop();
    ans[x]=ch[x].size()-1-pq[x].top().second;
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
    dfs(1,0);
    for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
}