#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
const int mn=3e5+10;
deque<pll>cvx;
bool bad(pll a,pll b,pll c){return (c.second-b.second)/(b.first-c.first)<=(b.second-a.second)/(a.first-b.first);}
void insi(pll a){
    if(cvx.size()&&a.first==cvx.back().first){
        if(a.second<cvx.back().second)a.second=cvx.back().second;
        cvx.pop_back();
    }
    while(cvx.size()>=2&&bad(cvx[cvx.size()-2],cvx[cvx.size()-1],a))cvx.pop_back();
    cvx.push_back(a);
}
void insd(pll a){
    if(cvx.size()&&a.first==cvx[0].first){
        if(a.second<cvx[0].second)a.second=cvx[0].second;
        cvx.pop_front();
    }
    while(cvx.size()>=2&&bad(a,cvx[0],cvx[1]))cvx.pop_front();
    cvx.push_front(a);
}
ll eval(pll l,ll x){return l.first*x+l.second;}
ll query(ll x){
    if(!cvx.size())return 0xc0c0c0c0c0c0c0c0;
    int cur=-1;
    for(int i=1<<17;i;i>>=1){
        if(cur+i+1>=cvx.size())continue;
        if(eval(cvx[cur+i],x)<eval(cvx[cur+i+1],x))cur+=i;
    }
    return eval(cvx[cur+1],x);
}
ll a[mn],s[mn],o[mn];
int main(){
    int n;
    scanf("%d",&n);
    ll ini=0,ans=0;
    for(int i=1;i<=n;i++)scanf("%lld",a+i),s[i]=s[i-1]+a[i],ini+=i*a[i];
    for(int i=1;i<=n;i++){
        ans=max(ans,query(a[i])-a[i]*i+s[i-1]);
        insi({i,-s[i-1]});
    }
    cvx.clear();
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        ans=max(ans,query(a[i])+a[i]*i-s[i-1]);
        insd({-i,s[i-1]});
    }
    printf("%lld",ans+ini);
}