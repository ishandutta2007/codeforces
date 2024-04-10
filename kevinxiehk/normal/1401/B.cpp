#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a0,a1,a2,b0,b1,b2;
    cin>>a0>>a1>>a2>>b0>>b1>>b2;
    int ans=0;
    int t=min(a2,b1);
    ans+=t*2;
    int tt=a1+b2;
    tt=max(0,tt-(a0+a1+a2-t));
    ans-=tt*2;
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}