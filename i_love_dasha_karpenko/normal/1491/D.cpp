//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg
const ll DIM = 40+7;
ll cnt[DIM];
int solve(ll step){
    ll u,v;
    cin>>u>>v;
    if (v<u){
        cout<<"NO\n";
        return 0;
    }
    vector<ll> V1,V2;
    ll ptr = 0;
    while(u){
        if (u&1)
        V1.push_back(ptr);
        u/=2;
        ++ptr;
    }
    ptr = 0;
    while(v){
        if (v&1)
        V2.push_back(ptr);
        v/=2;
        ptr++;
    }
    if (V2.size()>V1.size()){
        cout<<"NO\n";
        return 0;
    }
    ll flag = 0;

    while (!V2.empty()) {
        if (V1.empty()){
            cout<<"NO\n";
            return 0;
        }
        ll a = V1.back(), b = V2.back();
        V1.pop_back(), V2.pop_back();
        if (a<b)flag = 1;
        while(!V1.empty() && a>b){
            a = V1.back();
            V1.pop_back();
        }
        if (a>b){
            cout<<"NO\n";
            return 0;
        }
    }

    cout<<"YES\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    ll ptr = 0;
    while(t--)
        solve(++ptr);

    return 0;
}