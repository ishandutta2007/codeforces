#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int mn=1e5+10;
pll p[mn];
ll m,d;
bool comp(pll a,pll b){
    return a.second<b.second;
}
ll sq(ll x){return x*x;}
ll solve(int a,int b){
    if(a==b)return 0x3f3f3f3f3f3f3f3f;
    int mid=a+b>>1,i,j;
    ll ans=0x3f3f3f3f3f3f3f3f;
    ans=min(ans,solve(a,mid));
    ans=min(ans,solve(mid+1,b));
    d=ans;
    m=p[mid].first;
    vector<pll>v;
    for(i=a;i<=b;i++){
        if((m-p[i].first)*(m-p[i].first)<=d)v.push_back(p[i]);
    }
    sort(v.begin(),v.end(),comp);
    for(i=0;i<v.size();i++){
        for(j=max(0,i-6);j<i;j++){
            ans=min(ans,sq(v[i].first-v[j].first)+sq(v[i].second-v[j].second));
        }
    }
    return ans;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&p[i].second);
        if(i)p[i].second+=p[i-1].second;
        p[i].first=i;
    }
    sort(p,p+n);
    printf("%lld",solve(0,n-1));
}