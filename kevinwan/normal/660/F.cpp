#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=2e5+10;
ll a[mn],p[mn];
ll pos[mn],ad[mn];
vector<pll>cvx;
ll di(ll a,ll b){return a/b-((a^b)<0&&a%b);}
inline bool bad(pll a,pll b,pll c){
    return di((c.second-b.second),(b.first-c.first))<=di((b.second-a.second),(a.first-b.first));
}
int cur=0;
void ins(pll l){
    while(cvx.size()>=2&&bad(cvx[cvx.size()-2],cvx.back(),l))cvx.pop_back();
    cvx.push_back(l);
}
ll eval(pll l,ll x){
    return l.first*x+l.second;
}
ll query(ll x){
    int cur=-1;
    for(int i=1<<17;i;i>>=1){
        if(cur+i+1>=cvx.size())continue;
        if(eval(cvx[cur+i+1],x)>eval(cvx[cur+i],x))cur+=i;
    }
    return eval(cvx[cur+1],x);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    for(int i=n;i>=1;i--)pos[i]=pos[i+1]+a[i],ad[i]=ad[i+1]-(i+1)*a[i];
    for(int i=n;i>=1;i--)a[i]+=a[i+1];
    for(int i=n;i>=1;i--)a[i]+=a[i+1];
    ll ans=0;
    for(int i=1;i<=n;i++){
        ins({i,a[i]});
        ans=max(ans,query(pos[i+1])+ad[i+1]);
    }
    printf("%lld",ans);
}