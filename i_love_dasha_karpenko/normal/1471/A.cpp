//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        ll res = 0,sum = 0;
        for(ll i = 1;i<=n;++i){
            ll val;
            cin>>val;
            res = res+val/x+(val%x!=0);
            sum+=val;
        }
        sum = sum/x+(sum%x!=0);
        cout<<sum<<' '<<res<<endl;
    }

    return 0;
}