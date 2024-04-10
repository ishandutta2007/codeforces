//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;

void solve(){
    ll n;
    cin>>n;
    ll res = n*25;
    for(int a = 0;a<=5;++a){
        for(int b = 0;b<=5;++b){
            ll su = a*6+b*8;
            ll left = max(0ll,n-su);
            ll r = a*15+b*20+(left/10+(left%10!=0))*25;
            res = min(res,r);
        }
    }
    cout<<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}