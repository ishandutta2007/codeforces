#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
void solve(){
    int m,d,w;
    cin>>m>>d>>w;
    int t=__gcd(d-1,w);
    int tt=min(m,d);
    //cout<<t<<" "<<tt<<endl;
    w/=t;
    int aaa=w-tt%w;
    tt-=w;
    tt+=aaa;
    int ans=(tt*(tt/w+1));
    ans/=2;
    ans-=aaa*(tt/w);
    cout<<ans<<endl;
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}