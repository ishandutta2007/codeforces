#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int mn=1e5+10;
vector<int>g[mn],w[mn];
pii bes[mn];
int fr[mn];
pair<pii,int> me[mn];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m,i;
    cin>>n>>m;
    for(i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a>b)swap(a,b);
        g[a].push_back(b);
        g[b].push_back(a);
        w[a].push_back(-c);
        w[b].push_back(-c);
        me[i]={{a,b},c};
    }
    priority_queue<pair<pii,int>,vector<pair<pii,int>>,greater<pair<pii,int>>>pq;
    memset(bes,0x3f,sizeof(bes));
    bes[1]={0,0};
    pq.push({bes[1],1});
    while(pq.size()){
        int x=pq.top().second;
        pii v=pq.top().first;
        pq.pop();
        if(bes[x]!=v)continue;
        for(i=0;i<g[x].size();i++){
            int y=g[x][i],sd=w[x][i];
            pii pos={v.first+1,v.second+sd};
            if(pos<bes[y])bes[y]=pos,fr[y]=x,pq.push({bes[y],y});
        }
    }
    set<pii> use;
    int x=n;
    while(x!=1){
        use.insert({min(x,fr[x]),max(x,fr[x])});
        x=fr[x];
    }
    vector<pair<pii,int>> ch;
    for(i=0;i<m;i++){
        bool u=use.find(me[i].first)!=use.end();
        if(u!=me[i].second){
            ch.push_back(me[i]);
        }
    }
    printf("%d\n",ch.size());
    for(auto th:ch){
        printf("%d %d %d\n",th.first.first,th.first.second,1-th.second);
    }
    return 0;
}