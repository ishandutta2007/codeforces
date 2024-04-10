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
const ll DIM = 2*10E2 +7;
const ll INF = 10E17;
const ll MAXN = 10E5;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    t = 1;
    forn(qe,t){
        ll n;
        cin>>n;
        ll a,b,k;
        cin>>a>>b>>k;
        ll sum = a+b,res = 0;
        vector<ll> V;
        forn(i,n){
            ll x; cin>>x;
            x%=sum;
            if (x==0)x+=sum;
            if (x<=a)res++;
            else V.pb(x/a+(x%a!=0?1:0)-1);
        }
        sort(V.begin(),V.end(),greater<ll>());
        while(!V.empty()){
            if (k<V.back())break;
            k-=V.back();
            res++;
            V.pop_back();
        }
        cout<<res<<endl;
    }
    return 0;
}