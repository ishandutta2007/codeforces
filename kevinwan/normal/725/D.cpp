#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e6+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
pll a[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second,a[i].second-=a[i].first-1;
    sort(a+1,a+n,greater<pll>());
    int cur=1;
    priority_queue<ll>pq;
    while(cur<n&&a[0].first<a[cur].first)pq.push(-a[cur++].second);
    int ans=pq.size();
    cerr<<ans<<endl;
    while(pq.size()){
        ll x=pq.top();
        pq.pop();
        a[0].first+=x;
        if(a[0].first<0)break;
        while(cur<n&&a[0].first<a[cur].first)pq.push(-a[cur++].second);
        ans=min(ans,(int)pq.size());
    }
    printf("%d",ans+1);
}