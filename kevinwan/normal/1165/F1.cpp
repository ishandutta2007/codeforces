#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const ll mod=1e9+7;
const int mn=5e5+10;
ll k[mn],tot,t[mn];
pii o[mn];
int n,m;
bool solve(ll x){
    memcpy(t,k,sizeof(t));
    ll u=0;
    ll sp=0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<m;i++){
        pii p=o[i];
        if(p.first>x)continue;
        sp=min(sp,(ll)p.first);
        ll uu=min(sp,t[p.second]);
        t[p.second]-=uu;
        u+=uu;
        sp-=uu;
    }
    if(u+(tot-u)*2<=x)return 1;
    return 0;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",k+i),tot+=k[i];
    for(int i=0;i<m;i++)scanf("%d%d",&o[i].first,&o[i].second);
    sort(o,o+m,greater<pii>());
    ll cur=-1;
    for(ll i=1LL<<42;i;i>>=1){
        if(!solve(cur+i))cur+=i;
    }
    printf("%lld",cur+1);
}