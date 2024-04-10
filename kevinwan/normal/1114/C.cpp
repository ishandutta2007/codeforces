#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
ll get(ll n,ll p){
    ll ans=0;
    while(n/=p)ans+=n;
    return ans;
}
int main(){
    ll ans=0x3f3f3f3f3f3f3f3f;
    cin.tie(0);
    cin.sync_with_stdio(0);
    ll n,b,i;
    cin>>n>>b;
    for(i=2;i*i<=b;i++){
        int num=0;
        while(b%i==0){
            b/=i;
            num++;
        }
        if(num)ans=min(ans,get(n,i)/num);
    }
    if(b-1)ans=min(ans,get(n,b));
    cout<<ans;
}