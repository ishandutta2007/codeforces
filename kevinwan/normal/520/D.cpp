#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const ll mod=1e9+9;
const int mn=1e5+10;
pii pos[mn];
map<pii,int>m;
set<int>s;
int rel(pii p){
    if(!m[p])return 0;
    return (m[{p.first-1,p.second-1}]>0)+(m[{p.first,p.second-1}]>0)+(m[{p.first+1,p.second-1}]>0);
}
void upd(pii p){
    if(!m[p])return;
    s.insert(m[p]);
    if(rel({p.first-1,p.second+1})==1)s.erase(m[p]);
    if(rel({p.first,p.second+1})==1)s.erase(m[p]);
    if(rel({p.first+1,p.second+1})==1)s.erase(m[p]);
}
ll po[mn];
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d%d",&pos[i].first,&pos[i].second),m[pos[i]]=i;
    for(i=1;i<=n;i++)upd(pos[i]);
    po[0]=1;
    for(i=1;i<n;i++)po[i]=po[i-1]*n%mod;
    ll ans=0;
    for(i=0;i<n;i++){
        int x;
        if(i&1)x=*s.begin();
        else x=*(--s.end());
        s.erase(x);
        m[pos[x]]=0;
        upd({pos[x].first+1,pos[x].second});
        upd({pos[x].first+2,pos[x].second});
        upd({pos[x].first-1,pos[x].second});
        upd({pos[x].first-2,pos[x].second});
        upd({pos[x].first,pos[x].second-1});
        upd({pos[x].first-1,pos[x].second-1});
        upd({pos[x].first+1,pos[x].second-1});
        ans+=(x-1)*po[n-1-i];
        ans%=mod;
    }
    printf("%lld",ans);
}