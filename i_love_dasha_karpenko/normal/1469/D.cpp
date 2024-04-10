#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define x1 fgdfgdg
#define y1 fghgfhgfh
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<pair<ll,ll> > ans;
        while(n>2){
            ll ptr = n;
            for(ll i = n;i>=1;--i){
                if (n/(i-1)+(n%(i-1)!=0)>i-1)break;
                ptr = i;
            }
            for(ll i = n-1;i>=ptr;--i){
                ans.push_back({i,n});
            }
            ans.push_back({n,ptr-1});
            ans.push_back({n,n/(ptr-1)+(n%(ptr-1)!=0)});
           // cout<<n/(ptr-1)+(n%(ptr-1)!=0)<<' ';
            n = ptr-1;
            //cout<<ptr<<endl;
        }
        cout<<ans.size()<<endl;
        for(auto to:ans)cout<<to.first<<' '<<to.second<<endl;
    }
    return 0;
}