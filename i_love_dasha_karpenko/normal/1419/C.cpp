//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        ll flag = 0,f = 0,su = 0;
        for(ll i = 1;i<=n;++i) {
            ll re;
            cin>>re;
            su+=re-x;
            if (re==x)flag = 1;
            if (re!=x)f = 1;
        }
        if (f==0)cout<<"0\n";
        else if (flag==1 || su==0)cout<<"1\n";
        else cout<<"2\n";

    }
    return 0;
}