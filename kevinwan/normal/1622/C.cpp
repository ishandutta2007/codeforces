#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mn=2e5+10;

ll a[mn];
void solve(){
    ll n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    ll sum=0;
    for(int i=0;i<n;i++)sum+=a[i];
    ll ans=0;
    for(int i=n-1;i>0;i--){
        if(sum<=k){
            printf("%lld\n",ans);
            return;
        }
        if(a[i]-a[0]<n-i){
            ll mnum=(n-i)-(a[i]-a[0]);
            if(sum-(n-i)*mnum<=k){
                printf("%lld\n",(sum-k+n-i-1)/(n-i)+ans);
                return;
            }
            else{
                ans+=mnum;
                sum-=mnum*(n-i);
                a[0]-=mnum;
            }
        }
        sum-=a[i]-a[0];
        ans++;
    }
    if(sum<=k)printf("%lld\n",ans);
    else printf("%lld\n",(sum-k+n-1)/n+ans);
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
}