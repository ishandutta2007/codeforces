//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 1E5+100;
ll vis[DIM];
vector<ll> simp;
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(ll i = 2;i<DIM;++i){
        if (vis[i])
            continue;
        simp.push_back(i);
        for(ll j = i*i;j<DIM;j+=i)
            vis[j] = 1;
    }
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll res = 1;
        if (n%2){
            cout<<"NO\n";
            continue;
        }
        for(ll to:simp){
            if (to*to>n)
                break;
            ll ct = 0;
            while(n%to==0){
                n/=to;
                ct^=1;
            }
            if (ct)
                res*=to;
        }
        res*=n;
        if (res>2){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
    return 0;
}