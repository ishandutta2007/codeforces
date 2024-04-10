#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define pb push_back
#define endl '\n'
#define po(x) (1ll<<x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 2*10E4+7;
const ll INF = 10E16;
const ll MAXN = 10E4+1;
ll A[DIM];
ll suf1[DIM],suf2[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll n; cin>>n;
        n*=2;
        suf1[0] = 0;
        suf2[0] = 0;
        ll res = 0;
        forn(i,n){cin>>A[i];if (A[i]==1)res--; else res++; suf1[i]= INF;suf2[i] = INF;}
        ll sum = 0;
        for(ll i = n/2;i>=1;i--){
            if (A[i]==1)sum--;
            else sum++;
            if (sum<0)suf2[-sum] = min(suf2[-sum],n/2-i+1);
            else suf1[sum] = min(suf1[sum],n/2-i+1);
        }
        sum = 0; ll ans = INF;
        if (res==0)ans = 0;
        for(ll i = n/2+1;i<=n;i++){
            if (A[i]==1)sum--;
            else sum++;
            ll dif = res-sum;
            if (dif<0)ans = min(ans,suf2[-dif]+i-n/2);
            else ans = min(ans,suf1[dif]+i-n/2);
        }
        if (res<0)ans = min(ans,suf2[-res]);
        else ans = min(ans,suf1[res]);
        cout<<ans<<endl;
    }
    return 0;
}

// 1 2 3
//