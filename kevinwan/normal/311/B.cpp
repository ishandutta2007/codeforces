#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
const int mn=1e5+10;
ll d[mn];
ll t[mn],pt[mn];
inline bool bad(pll a,pll b,pll c){return (c.second-a.second)*(a.first-b.first)<=(b.second-a.second)*(a.first-c.first);}
vector<pll>cvx[101];
ll dp[mn][101];
int cur[101];
void ins(vector<pll>&cvx,pll l){
    while(cvx.size()>=2&&bad(cvx[cvx.size()-2],cvx[cvx.size()-1],l)){
        cvx.pop_back();
    }
    cvx.push_back(l);
}
inline ll eval(pll l,ll x){return l.first*x+l.second;}
ll qu(int i,ll x){
    if(cur[i]>=cvx[i].size())cur[i]=cvx[i].size()-1;
    while(cur[i]+1<cvx[i].size()&&eval(cvx[i][cur[i]],x)>eval(cvx[i][cur[i]+1],x))cur[i]++;
    return eval(cvx[i][cur[i]],x);
}
int main(){
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    for(int i=2;i<=n;i++)scanf("%lld",d+i),d[i]+=d[i-1];
    for(int i=1;i<=m;i++){
        ll a,b;
        scanf("%lld%lld",&a,&b);
        t[i]=b-d[a];
    }
    sort(t+1,t+1+m);
    for(int i=1;i<=m;i++)pt[i]=t[i]+pt[i-1];
    for(int i=0;i<p;i++)ins(cvx[i],{0,0});
    for(int i=1;i<=m;i++){
        for(int j=1;j<=p;j++){
            dp[i][j]=i*t[i]-pt[i]+qu(j-1,t[i]);
            ins(cvx[j],{-i,dp[i][j]+pt[i]});
        }
    }
    ll ans=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=p;i++)ans=min(ans,dp[m][i]);
    printf("%lld",ans);
}