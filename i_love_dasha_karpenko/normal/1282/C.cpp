#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree <ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
#define fi first
#define sc second
#define x1 Tanya
#define y1 Romanova
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define endl '\n'
const ll DIM = 2*10E4+7;
const ll INF = 10E17;
pp A[DIM];
ll cnta[DIM],cntb[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll tiew; cin>>tiew;
    forn(q,tiew){
        ll n,t,a,b;
        cin>>n>>t>>a>>b;
        forn(i,n){
            ll x; cin>>x;
            if (x==0)A[i].sc = a;
            else A[i].sc = b;
        }
        forn(i,n)cin>>A[i].fi;
        sort(A+1,A+1+n);
        cnta[n+1] = cntb[n+1] = 0;

        for(ll i = n;i>=1;i--){
            cnta[i] = cnta[i+1];
            cntb[i] = cntb[i+1];
            if (A[i].sc==a)cnta[i]++;
            else cntb[i]++;
        }
        ll pref = 0,res = 0;
        forn(i,n){
            ll tb = A[i].fi-1;
            if (tb<0){pref+=A[i].sc;continue;}
            ll cnt = i-1;
            ll tl = tb-pref;
            if (tl<0){
                pref+=A[i].sc;
                continue;
            }
            ll g = min(tl/a,cnta[i]);
            tl-=g*a;
            cnt+=g;
            g = min(tl/b,cntb[i]);
            cnt+=g;
            res = max(res,cnt);
            pref+=A[i].sc;
        }
        if (pref<=t)res = n;
        cout<<res<<endl;
    }
    return 0;
}