#include <bits/stdc++.h>
using namespace std;
const int mn=1e3+10;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
vector<int> g[mn];
vector<ll> d[mn];
const ll big=1e15;
ll dis[mn][mn],ans[mn][mn],dis2[mn];
int bac[mn],e1[mn*10],e2[mn*10];
void kill(){
    printf("NO");
    exit(0);
}
int main()
{
    int n,m,s,t,i;
    ll l;
    scanf("%d%d%lld%d%d",&n,&m,&l,&s,&t);
    int a,b;
    ll c;
    for(i=0;i<m;i++){
        scanf("%d%d%lld",&a,&b,&c);
        g[a].push_back(b);
        g[b].push_back(a);
        d[a].push_back(c);
        d[b].push_back(c);
        e1[i]=a,e2[i]=b;
        if(a<b)swap(a,b);
        ans[a][b]=ans[b][a]=c;
    }
    priority_queue<pli,vector<pli>,greater<pli>>pq;
    memset(dis,0x3f,sizeof(dis));
    memset(dis2,0x3f,sizeof(dis2));
    for(i=0;i<n;i++){
        dis[i][i]=0;
        pq.push({dis[i][i],i});
        while(pq.size()){
            int x=pq.top().second;
            ll di=pq.top().first;
            pq.pop();
            if(di!=dis[i][x])continue;
            for(int j=0;j<g[x].size();j++){
                int y=g[x][j];
                ll pos=di+d[x][j];
                if(d[x][j]==0)pos+=big;
                if(pos<dis[i][y]){
                    dis[i][y]=pos;
                    pq.push({pos,y});
                }
            }
        }
    }
    if(dis[s][t]<l)kill();
    dis2[s]=0;
    pq.push({0,s});
    while(pq.size()){
        int x=pq.top().second;
        ll di=pq.top().first;
        pq.pop();
        if(di!=dis2[x])continue;
        for(int j=0;j<g[x].size();j++){
            int y=g[x][j];
            ll pos=di+d[x][j];
            if(d[x][j]==0)pos++;
            if(pos<dis2[y]){
                dis2[y]=pos;
                bac[y]=x;
                pq.push({pos,y});
            }
        }
    }
    if(dis2[t]>l)kill();
    int cur=t;
    ll tot=0;
    while(cur!=s){
        tot+=dis[cur][bac[cur]];
        cur=bac[cur];
    }
    ll dif=tot-l,curl=0;
    cur=t;
    while(cur!=s){
        a=bac[cur],b=cur;
        if(!ans[a][b]){
            ans[a][b]=max(l-dis[s][a]-curl,dis[a][b]-min(dif,dis[a][b]-1));
            dif-=dis[a][b]-ans[a][b];
        }
        curl+=ans[a][b];
        ans[b][a]=ans[a][b];
        assert(curl<=dis[a][t]);
        cur=bac[cur];
    }
    printf("YES\n");
    for(i=0;i<m;i++){
        printf("%d %d ",e1[i],e2[i]);
        a=max(e1[i],e2[i]),b=min(e1[i],e2[i]);
        if(ans[a][b])c=ans[a][b];
        else c=big;
        printf("%lld\n",c);
    }
}