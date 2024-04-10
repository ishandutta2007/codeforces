#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e5+10;
int main(){
    ll n;
    scanf("%lld",&n);
    if(n%3){
        printf("0");
        return 0;
    }
    n/=3;
    vector<ll>f;
    for(ll i=1;i*i<=n;i++){
        if(n%i)continue;
        f.push_back(i);
        if(i*i!=n)f.push_back(n/i);
    }
    sort(f.begin(),f.end());
    int ans=0;
    for(ll x:f){
        ll lim=n/x;
        for(ll y:f){
            if(y>lim)break;
            ll z=n/(x*y);
            if(x*y*z!=n)continue;
            int no=(x&1)^(y&1)^(z&1);
            if(no)continue;
            if(x>=y+z||y>=x+z||z>=x+y)continue;
            ans++;
        }
    }
    printf("%d",ans);
}