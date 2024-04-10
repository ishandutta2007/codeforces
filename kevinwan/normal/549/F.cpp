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
struct event{
    int t,x,v;
};
ll a[mn],ac[mn];
int lb[mn],rb[mn];
ll cur[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i],ac[i]=(ac[i-1]+a[i])%k;
    stack<int>s;
    a[0]=a[n+1]=inf;
    s.push(0);
    for(int i=1;i<=n;i++){
        while(a[i]>=a[s.top()])s.pop();
        lb[i]=s.top()+1;
        s.push(i);
    }
    while(s.size())s.pop();
    s.push(n+1);
    for(int i=n;i>=1;i--){
        while(a[i]>a[s.top()])s.pop();
        rb[i]=s.top()-1;
        s.push(i);
    }
    vector<event>v;
    for(int i=1;i<=n;i++){
        if(rb[i]-i<i-lb[i]){
            for(int j=i;j<=rb[i];j++){
                int tar=(-a[i]+ac[j])%k;
                if(tar<0)tar+=k;
                v.push_back({i-1,tar,1});
                v.push_back({lb[i]-2,tar,-1});
            }
        }
        else{
            for(int j=i;j>=lb[i];j--){
                int tar=(a[i]+ac[j-1])%k;
                if(tar<0)tar+=k;
                v.push_back({rb[i],tar,1});
                v.push_back({i-1,tar,-1});
            }
        }
    }
    ll ans=0;
    sort(v.begin(),v.end(),[](auto a,auto b){return a.t<b.t;});
    int t=-1;
    for(event e:v){
        while(t<e.t)cur[ac[++t]]++;
        cerr<<e.t<<' '<<e.x<<' '<<e.v<<' '<<cur[e.x]*e.v<<'\n';
        ans+=cur[e.x]*e.v;
    }
    printf("%lld",ans-n);
}