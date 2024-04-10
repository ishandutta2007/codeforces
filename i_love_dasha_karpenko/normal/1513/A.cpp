#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        if (k*2>=n){
            cout<<"-1\n";
            continue;
        }
        if (k==0){
            for(ll i = 1;i<=n;++i){
                cout<<i<<' ';
            }
            cout<<endl;
        }
        else{
            ll ptr = 1;
            cout<<ptr<<' ';
            while(k>1){
                cout<<ptr+2<<' '<<ptr+1<<' ';
                ptr+=2;
                --k;
            }
            for(ll i = n;i>ptr;--i)
                cout<<i<<' ';
            cout<<endl;
        }
    }
    return 0;
}