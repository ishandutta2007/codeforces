#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll INF = 1E18;
void solve(){
    pair<ll,ll> dots[4];
    for(ll i = 0;i<4;++i)cin>>dots[i].first>>dots[i].second;
    sort(dots,dots+4);
    ll ans = INF;
    ll ct = 0;
    while(next_permutation(dots,dots+4)){
        ++ct;
        ll res = 0;
        res+=abs(dots[0].first-dots[1].first);
        ll l1 = min(dots[0].first,dots[1].first);
        ll r1 = max(dots[0].first,dots[1].first);
        res+=abs(dots[2].first-dots[3].first);
        ll l2 = min(dots[2].first,dots[3].first);
        ll r2 = max(dots[2].first,dots[3].first);
        if (r2<l1)continue;
        ll L1 = max(0ll,l2-r1),R1 = max(0ll,r2-l1);
        res+=abs(dots[1].second-dots[2].second);
        l1 = min(dots[1].second,dots[2].second);
        r1 = max(dots[1].second,dots[2].second);
        res+=abs(dots[0].second-dots[3].second);
        l2 = min(dots[0].second,dots[3].second);
        r2 = max(dots[0].second,dots[3].second);
        if (r2<l1)continue;
        ll L2 = max(0ll,l2-r1),R2 = max(0ll,r2-l1);
        if (L2>R1 || L1>R2){
            if (L2>R1)res+=(L2-R1)*2;
            else res+=(L1-R2)*2;
        }
        ans = min(ans,res);
    }
    for(ll i =0;i<1;++i){


        ll res = 0;
        res+=abs(dots[0].first-dots[1].first);
        ll l1 = min(dots[0].first,dots[1].first);
        ll r1 = max(dots[0].first,dots[1].first);
        res+=abs(dots[2].first-dots[3].first);
        ll l2 = min(dots[2].first,dots[3].first);
        ll r2 = max(dots[2].first,dots[3].first);
        if (r2<l1)continue;
        ll L1 = max(0ll,l2-r1),R1 = max(0ll,r2-l1);
        res+=abs(dots[1].second-dots[2].second);
        l1 = min(dots[1].second,dots[2].second);
        r1 = max(dots[1].second,dots[2].second);
        res+=abs(dots[0].second-dots[3].second);
        l2 = min(dots[0].second,dots[3].second);
        r2 = max(dots[0].second,dots[3].second);
        if (r2<l1)continue;
        ll L2 = max(0ll,l2-r1),R2 = max(0ll,r2-l1);
        if (L2>R1 || L1>R2){
            if (L2>R1)res+=(L2-R1)*2;
            else res+=(L1-R2)*2;
        }
        ans = min(ans,res);
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }


    return 0;
}