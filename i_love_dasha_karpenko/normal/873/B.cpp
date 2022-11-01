#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
//typedef tree(ll,null_type,less<ll>,tree_order_statistics_node_update,rb_tree_tag> super_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
const ll DIM = 100000+4;
const ll INF = 10E17;
const ll MOD = 10E8+7;
const ll MAXN = 26;
ll mi[DIM*2+14];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin>>n;
    ll pref = 0;
    memset(mi,-1,sizeof(mi));
    ll res = 0;
    mi[0+DIM] = 0;
    forn(i,n){
        char ch; cin>>ch;
        if (ch=='0')pref--;
        else pref++;
        if (mi[pref+DIM]==-1)mi[pref+DIM] = i;
        res = max(res,i-mi[pref+DIM]);
    }
    cout<<res<<endl;
    return 0;
}