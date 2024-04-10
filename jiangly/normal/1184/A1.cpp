#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll r;
    cin>>r;
    --r;
    for(ll x=1;x*(x+3)<=r;++x){
        if((r-x*(x+1))%(x*2)==0){
            cout<<x<<' '<<(r-x*(x+1))/(x*2)<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}