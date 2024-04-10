#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef pair<double,double>pdd;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef long long ll;
const int mn=1e6+10;
bool die(pll a,pll b,pll c){
    return ((c.second-b.second))/(b.first-c.first)<=((b.second-a.second))/(a.first-b.first);
}
deque<pll>cvx;
void ins(pll l){
    if(cvx.size()&&l.first==cvx[0].first){
        if(l.second>cvx[0].second)cvx.pop_front();
        else l=cvx[0],cvx.pop_front();
    }
    while(cvx.size()>=2&&die(l,cvx[0],cvx[1]))cvx.pop_front();
    cvx.push_front(l);
}
ll eval(pll l,ll x){
    return l.first*x+l.second;
}
ll query(ll x){
    int cur=-1;
    for(int i=1<<19;i;i>>=1){
        if(cur+i+1>=cvx.size())continue;
        if(eval(cvx[cur+i],x)<eval(cvx[cur+i+1],x))cur+=i;
    }
    return eval(cvx[cur+1],x);
}
ll ans;
struct three{ll x,y,a;bool operator<(const three&ot)const{return x<ot.x;}};
three h[mn];
int main(){
    //freopen("//Users//kevinwan//Desktop//wtf.txt","r",stdin);
    memset(h,0,sizeof(h));
    ans=0;
    int n;
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>h[i].x>>h[i].y>>h[i].a;
    ins({0,0});
    sort(h+1,h+n+1);
    for(int i=1;i<=n;i++){
        ll bes=h[i].x*h[i].y-h[i].a+query(h[i].y);
        ans=max(ans,bes);
        ins({-h[i].x,bes});
    }
    printf("%lld",ans);
}
/*
 * Remember to watch out for undefined behaviour
 *  - unstable sorts
 *  - array bounds
 *  - convex hull is only a convex function over x, not over the lines
 *
 */