#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=998244353;
const int mn=3e5+10;
vector<pll>g[mn];
ll dis[mn];
int ori[mn];
struct th{
    ll d;
    int o,x;
    bool operator<(const th&o)const {return d>o.d;}
};
struct edge{int a,b;ll c;};
int cur[mn];
vector<int>ask[mn];
int p[mn];
int f(int x){return x==p[x]?x:(p[x]=f(p[x]));}
int aa[mn],bb[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    for(int i=0;i<m;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    memset(dis,0x3f,sizeof(dis));
    priority_queue<th>pq;
    for(int i=1;i<=k;i++)pq.push({0,i,i});
    while(pq.size()){
        th t=pq.top();
        pq.pop();
        if(dis[t.x]!=0x3f3f3f3f3f3f3f3f)continue;
        dis[t.x]=t.d;
        ori[t.x]=t.o;
        for(pll p:g[t.x]){
            pq.push({t.d+p.second,t.o,(int)p.first});
        }
    }
    vector<edge>v;
    for(int i=1;i<=n;i++)for(pii p:g[i])if(p.first>i)v.push_back({ori[i],ori[p.first],p.second+dis[i]+dis[p.first]});
    sort(v.begin(),v.end(),[](auto a,auto b){return a.c<b.c;});
    memset(cur,-1,sizeof(cur));
    for(int i=0;i<q;i++)cin>>aa[i]>>bb[i];
    for(int i=1<<18;i;i>>=1){
        for(int i=0;i<v.size();i++)ask[i].clear();
        iota(p,p+mn,0);
        for(int j=0;j<q;j++)if(cur[j]+i<v.size())ask[cur[j]+i].push_back(j);
        for(int j=0;j<v.size();j++){
            p[f(v[j].a)]=f(v[j].b);
            for(int x:ask[j])if(f(aa[x])!=f(bb[x]))cur[x]+=i;
        }
    }
    for(int i=0;i<q;i++)printf("%lld\n",v[cur[i]+1].c);
}