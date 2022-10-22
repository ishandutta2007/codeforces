#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+7;
const int mn=1e6+10;
ll a[mn],l[mn],r[mn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m,m--;
    for(int i=1;i<=n;i++)cin>>a[i];
    a[0]=a[n+1]=LLONG_MAX;
    vector<int>s;
    s.push_back(0);
    for(int i=1;i<=n;i++){
        while(s.size()&&a[i]>=a[s.back()])s.pop_back();
        l[i]=i-s.back();
        s.push_back(i);
    }
    s.clear();
    s.push_back(n+1);
    for(int i=n;i>=1;i--){
        while(s.size()&&a[i]>a[s.back()])s.pop_back();
        r[i]=s.back()-i;
        s.push_back(i);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(l[i]>r[i])swap(l[i],r[i]);
        ll i1=(l[i]-1)/m,i2=(r[i]-1)/m,i3=(l[i]+r[i]-1)/m;
        ans+=(2+(i1+1)*m)*i1/2%mod*a[i];
        ans+=l[i]*(i2-i1)%mod*a[i];
        ans+=((l[i]+r[i])*2-2-(i3+i2+1)*m)*(i3-i2)/2%mod*a[i],ans%=mod;
    }
    printf("%lld",ans);
}