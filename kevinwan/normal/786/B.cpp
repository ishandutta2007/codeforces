#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=1e5+10;
vector<pii>g[mn];
vector<ll>w[mn];
vector<pii>ch;
ll dist[mn];
bool u[mn];
set<int> seg[mn*2];
priority_queue<pair<ll,pii>,vector<pair<ll,pii>>,greater<pair<ll,pii>>>pq;
void up(int a,int b,int c){
    a+=mn,b+=mn;
    while(a<=b){
        if(a&1)seg[a].insert(c);
        if(!(b&1))seg[b].insert(c);
        a++,b--;
        a>>=1,b>>=1;
    }
}
void qu(int a){
    int o=a;
    a+=mn;
    while(a){
        for(int x:seg[a]){
            if(!u[x]){
                u[x]=1;
                pq.push({dist[o]+ch[x].second,{ch[x].first,ch[x].first}});
            }
        }
        seg[a].clear();
        a>>=1;
    }
}
int p[mn];
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
int main()
{
    int n,q,beg,i;
    scanf("%d%d%d",&n,&q,&beg);
    for(i=0;i<q;i++){
        int a;
        scanf("%d",&a);
        if(a==1){
            int b,c,d;
            scanf("%d%d%d",&b,&c,&d);
            g[b].push_back({c,c});
            w[b].push_back(d);
        }
        if(a==2){
            int b,c,d,e;
            scanf("%d%d%d%d",&b,&c,&d,&e);
            g[b].push_back({c,d});
            w[b].push_back(e);
        }
        if(a==3){
            int b,c,d,e;
            scanf("%d%d%d%d",&b,&c,&d,&e);
            ch.push_back({b,e});
            up(c,d,ch.size()-1);
        }
    }
    memset(dist,0x3f,sizeof(dist));
    pq.push({0,{beg,beg}});
    iota(p,p+mn,0);
    while(pq.size()){
        int l=pq.top().second.first,r=pq.top().second.second;
        ll d=pq.top().first;
        pq.pop();
        int x=f(l);
        while(x<=r){
            dist[x]=d;
            for(i=0;i<g[x].size();i++){
                pii y=g[x][i];
                ll ex=w[x][i];
                pq.push({d+ex,y});
            }
            qu(x);
            p[x]=x+1;
            x=f(x);
        }
    }
    for(i=1;i<=n;i++){
        if(dist[i]==0x3f3f3f3f3f3f3f3f)printf("-1 ");
        else printf("%lld ",dist[i]);
    }
}