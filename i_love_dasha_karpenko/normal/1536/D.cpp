//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 5E5+7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        set<ll> S;
        ll last = -1E18,flag = 0;
        for(ll i = 1;i<=n;++i){
            ll x;
            cin>>x;
            if (last==-1E18){
                S.insert(x);
                last = x;
                continue;
            }
            if (last>x){
                S.insert(x);
                if (*S.upper_bound(x)!=last){
                    flag = 1;

                }
            }
            else if (last<x){
                S.insert(x);
                if (*S.upper_bound(last)!=x){
                    flag = 1;

                }
            }
            last = x;
        }
        if (flag)
            cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}