#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
//template<typename TN>
//typedef tree<TN,null_type,less<TN>,rb_tree_tag,tree_order_statistics_node_update> super_set<TN>;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
const ll DIM = 2*10E4 +7;
const ll INF = 10E17;
const ll MAXN = 10E5;
set<ll> S[30];
ll ans[DIM];
ll gi(char ch){
    return ch-'a'+1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll res = 0;
    for(ll i = 0;i<s.length();i++){
        ll v = gi(s[i]);
        set<ll> se;
        for(ll to:S[v+1])se.insert(to);
        ll col = 1;
        for(ll to:se){
            if (to==col)col++;
        }
        ans[i] = col;
        for(ll i = v;i>=1;i--){
            S[i].insert(col);
        }
        res = max(res,col);
    }
    cout<<res<<endl;
    forn(i,n){
        cout<<ans[i-1]<<' ';
    }
    cout<<endl;
    return 0;
}