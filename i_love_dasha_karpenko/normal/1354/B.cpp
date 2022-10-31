#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
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
const ll DIM = 100+14;
const ll INF = 1E17;

ll gi(char ch){
    return ch-'1';
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll last[3];
        last[0] = last[1] = last[2] = -INF;
        ll len = s.length();
        ll res = INF;
        for(ll i = 0;i<len;++i){
            last[gi(s[i])] = i;
            res =min(res,i- min(min(last[0],last[1]),last[2])+1);
        }
        if (res==INF)cout<<"0\n";
        else
        cout<<res<<endl;
    }
    return 0;
}