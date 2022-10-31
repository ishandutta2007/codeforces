//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define x1 dfgfg
#define y1 dfgdfg

void solve(){
    string s;
    cin>>s;
    ll n = s.length();
    for(ll i = -1;i<n;++i){
        vector<ll> V;
        for(ll j = 0;j<=i;++j){
            if (s[j]=='1')V.push_back(j);
        }
        for(ll j = i+1;j<n;++j){
            if (s[j]=='0')V.push_back(j);
        }
        ll prev = -2,flag = 0;
        for(ll to:V){
            if (to<=prev+1){
                flag = 1;
                break;
            }
            prev = to;
        }
        if (flag==0){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}