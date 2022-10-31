#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
const ll DIM = 8E5+7;
const ll MOD = 1E9+7;
ll A[DIM],pref[DIM];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        map<ll,ll> M;
        for(ll i = 1;i<=n;++i){
            cin>>A[i];
            pref[i] = (pref[i-1]^A[i]);
            if (i<n)
            M[pref[i]]++;
        }
        ll flag = 0;
        ll cur = 0;
        for(ll i = n;i>1;--i){
            cur = (cur^A[i]);
            if (cur==pref[i-1]){
                flag = 1;
            }
            if (pref[i-1]==0 && M.count(cur))
                flag = 1;
            M[pref[i-1]]--;
            if (M[pref[i-1]]==0)
                M.erase(pref[i-1]);
        }
        if (flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}