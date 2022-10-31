#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 200000  +7;
const ll INF = 10E10;
ll A[DIM],cost[DIM],dp[DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    forn(query,t){
        ll n,p,k;cin>>n>>p>>k;
        k--;
        forn(i,n){
            cin>>A[i];
        }
        sort(A+1,A+1+n);
        ll cnt = 0,res = 0,ans= 0;

        forn(i,n){
            //if (A[i]>p)break;
            if (k>=i){
                dp[i] = dp[i-1]+A[i];
                //res = i;
                continue;
            }
            ll val = dp[i-k-1];
            //if (val+A[i]>p)break;
            dp[i] = val+A[i];
            //res = i;
        }
        forn(i,n){
            if (dp[i]<=p)
            res = i;
        }
        cout<<res<<endl;
    }
    return 0;
}