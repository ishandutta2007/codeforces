#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
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
const ll DIM = 2*10E3+7;
const ll INF = 10E17;
const ll LOG = 21;
ll dp[DIM],ss[DIM],pref[DIM],sm[DIM],pm[DIM],olddp[DIM],A[DIM],T[DIM*4][2];
ll n,m,k;
void buildtree(ll t,ll tl,ll tr){
    if (tl==tr){
        T[t][0] = pm[tl]-pref[tl];

        T[t][1] = sm[tl];
        if (tl>=k)T[t][1]+=pref[tl-k];
        return;
    }
    ll tm = (tl+tr)/2;
    buildtree(t*2+1,tl,tm);
    buildtree(t*2+2,tm+1,tr);
    T[t][0] = max(T[t*2+1][0],T[t*2+2][0]);
    T[t][1] = max(T[t*2+1][1],T[t*2+2][1]);
}
pp query(ll t,ll tl,ll tr,ll l,ll r){
    if (tl>r || l>tr)return {-INF,-INF};
    if (l<=tl && tr<=r){
        return {T[t][0],T[t][1]};
    }
    ll tm = (tl+tr)/2;
    pp a1 = query(t*2+1,tl,tm,l,r);
    pp a2 = query(t*2+2,tm+1,tr,l,r);
    a1.fi = max(a1.fi,a2.fi);
    a1.sc = max(a1.sc,a2.sc);
    return a1;
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m>>k;
    forn(i,n){

        forn(i,m){
            cin>>A[i];
            pref[i] = pref[i-1]+A[i];
        }

        ll sum = 0;
        forn(i,m){
            sum+=A[i];
            if (i>k)sum-=A[i-k];
            ss[i] = sum;
        }
        if (i==1){
            forn(i,m){
                olddp[i] = ss[i];
            }
            continue;
        }
        forn(i,m){
            pm[i] = max(pm[i-1],olddp[i]+ss[i]);
        }
        for(ll i = m;i>=1;i--){
            sm[i] = max(sm[i+1],olddp[i]+ss[i]);
        }
        buildtree(0,0,m);
        forn(i,m){
            dp[i] = 0;
            pp q1 = query(0,0,m,max(0ll,i-k),i);
            pp q2 = query(0,0,m,i,min(m,i+k));
            dp[i] = max(dp[i],q1.fi+pref[i]);
            dp[i] = max(dp[i],q2.sc-pref[max(0ll,i-k)]);
            /*
            for(ll j = i;j>=max(0ll,i-k);j--){
                dp[i] = max(dp[i],pref[i]-pref[j]+pm[j]);
            }
            for(ll j = i+k;j>=i;j--){
                dp[i] = max(dp[i],pref[j-k]-pref[i-k]+sm[j]);
            }
            */
        }
        //cout<<dp[2]<<' '<<dp[3]<<endl;
        forn(i,m){
            //cout<<dp[i]<<' ';
            olddp[i] = dp[i];
            dp[i] = 0;
        }
       // cout<<endl;

    }
    ll res = 0;
    forn(i,m)res = max(res,olddp[i]);
    cout<<res<<endl;
    return 0;
}