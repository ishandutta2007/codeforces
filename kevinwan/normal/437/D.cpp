#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=1e5+10;
int pp[mn];
int fi(int x){return x==pp[x]?x:(pp[x]=fi(pp[x]));}
void init(int n){for(int i=1;i<=n;i++)pp[i]=i;}
ll k[mn];
pii ed[mn];
inline bool comp(const pii&a,const pii&b){return min(k[a.first],k[a.second])>min(k[b.first],k[b.second]);}
vector<int> g[mn];
int ord[mn];
inline bool comp2(const int&a,const int&b){if(k[a]!=k[b])return k[a]>k[b];return a>b;}
ll siz[mn];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m,i,a,b;
    cin>>n>>m;
    init(n);
    for(i=1;i<=n;i++)cin>>k[i];
    for(i=0;i<m;i++){
        cin>>a>>b;
        ed[i]={a,b};
    }
    sort(ed,ed+m,comp);
    for(i=0;i<m;i++){
        a=ed[i].first,b=ed[i].second;
        if(fi(a)!=fi(b)){
            g[a].push_back(b),g[b].push_back(a);
            pp[fi(a)]=fi(b);
        }
    }
    for(i=1;i<=n;i++)ord[i]=i;
    sort(ord+1,ord+n+1,comp2);
    ll tot=0;
    init(n);
    for(i=1;i<=n;i++){
        int x=ord[i];
        ll s,ss;
        s=ss=0;
        for(int y:g[x]){
            if(k[x]<k[y]||(k[x]==k[y]&&x<y)){
               s+=siz[fi(y)];
               ss+=siz[fi(y)]*siz[fi(y)];
               pp[fi(y)]=x;
            }
        }
        siz[x]=s+1;
        tot+=(s*s-ss+2*s)*k[x];
    }
    printf("%.100Lf",1.L*tot/n/(n-1));
}