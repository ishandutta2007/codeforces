#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef int ll;
typedef double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2E5+7;
const ll INF = 10E7;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
//
ll cnt[DIM][30],num[DIM];
ll gi (char ch){
    return ch-'a'+1;
}
int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll res =0;
        ll mid = k/2+(k%2!=0);
        ll dif = k/2;
        for(ll i = 0;i<s.length();i++){
            ll pos = i%k;
            if (pos>k-1-pos)pos=k-1-pos;
            cnt[pos][gi(s[i])]++;
            num[pos]++;
        }
        for(ll i = 0;i<k;i++){
            ll mx = 0;
            for(ll let = 1;let<30;let++){
                mx = max(mx,cnt[i][let]);
                cnt[i][let] = 0;
            }
            res+=num[i]-mx;
            num[i] = 0;
        }
        cout<<res<<endl;
    }
    return 0;
}