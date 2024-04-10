#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{int a,b,c;};
const int mn=2e5+10;
edge e[mn];
vector<int>g[mn],d[mn];
ll dis[800][800];
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        e[i]={a,b,c};
    }
    sort(e,e+m,[](edge a,edge b){return a.c<b.c;});
    vector<int>v;
    for(int i=0;i<k;i++)v.push_back(e[i].a),v.push_back(e[i].b);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    map<int,int>comp;
    for(int i=0;i<v.size();i++)comp[v[i]]=i;
    for(int i=0;i<k;i++){
        g[comp[e[i].a]].push_back(comp[e[i].b]);
        g[comp[e[i].b]].push_back(comp[e[i].a]);
        d[comp[e[i].a]].push_back(e[i].c);
        d[comp[e[i].b]].push_back(e[i].c);
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=0;i<v.size();i++){
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
        pq.push({0,i});
        while(pq.size()){
            int x=pq.top().second;
            ll vx=pq.top().first;
            pq.pop();
            if(dis[i][x]!=0x3f3f3f3f3f3f3f3f)continue;
            dis[i][x]=vx;
            for(int j=0;j<g[x].size();j++){
                pq.push({vx+d[x][j],g[x][j]});
            }
        }
    }
    vector<ll>ans;
    for(int i=0;i<v.size();i++)for(int j=i+1;j<v.size();j++)ans.push_back(dis[i][j]);
    sort(ans.begin(),ans.end());
    printf("%lld",ans[k-1]);
}