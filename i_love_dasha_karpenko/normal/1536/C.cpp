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
        map<pair<ll,ll>,ll> M;
        ll cnt1 = 0,cnt2 = 0;
        for(ll i = 1;i<=n;++i){
            char ch;
            cin>>ch;
            if (ch=='D')
                ++cnt1;
            else ++cnt2;
            pair<ll,ll> cur = {cnt1,cnt2};
            ll g = __gcd(cnt1,cnt2);
            cur.first/=g;
            cur.second/=g;
            cout<<M[cur]+1<<' ';
            M[cur]++;
        }
        cout<<endl;
    }
    return 0;
}