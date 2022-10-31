#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1ll;i<=n;++i)
#define pb push_back
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 300 +7;
const ll INF = 10E17+7;
const ll MAXN = 10E4+7;
ll ans[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll cnta,cntb;
    cout<<'a'<<endl;
    cin>>cnta;
    if (cnta==0)return 0;
    if (cnta==300){
        forn(i,cnta)cout<<'b';
        cout<<endl;
        cin>>cntb;
        return 0;
    }
    ll len = cnta+1;
    forn(i,len)cout<<'a';
    cout<<endl;
    cin>>cntb;
    if (cntb==len){
        forn(i,cnta)cout<<'b';
        cout<<endl;
        cin>>cntb;
        return 0;
    }
    if (cntb==0){
        return 0;
    }
    forn(pos,len-1){
        forn(i,len){
            if(i==pos || ans[i]==1)cout<<'b';
            else cout<<'a';
        }
        cout<<endl;
        ll a; cin>>a;
        if (a<cntb)ans[pos] = 1;
        cntb = min(cntb,a);
        if (a==0)return 0;
    }
    if (cntb!=0)ans[len] = 1;
    forn(i,len){
        cout<<(ans[i]==1?'b':'a');
    }
    cout<<endl;
    ll x; cin>>x;

    return 0;
}