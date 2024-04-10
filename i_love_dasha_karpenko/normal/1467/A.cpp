#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if (n<=2){
            ll cur = 9;
            for(ll i = 1;i<=n;++i){
                cout<<cur;
                cur = (cur+9)%10;
            }
            cout<<endl;
            continue;
        }
        cout<<"98";
        n-=2;
        ll cur = 9;
        for(ll i = 1;i<=n;++i){
            cout<<cur;
            cur = (cur+1)%10;
        }
        cout<<endl;
    }
    return 0;
}