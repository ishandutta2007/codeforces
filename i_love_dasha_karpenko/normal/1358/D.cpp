#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 4E5+140;
const ll INF = 1E19;

ll A[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,x;
    cin>>n>>x;
    forn(i,n)cin>>A[i];
    forn(i,n)A[i+n] = A[i];
    ll ptr = 1,sum = 0;
    ll res = 0;
    ll cnt = 0;
    forn(i,n*2){
        sum+=A[i];
        cnt+=A[i]*(A[i]+1)/2;
        while(sum>x){

            cnt-=A[ptr]*(A[ptr]+1)/2;
            sum-=A[ptr++];
        }
        ll delta = x-sum;
        delta = max(0ll,delta);
        delta = A[ptr-1]-delta;
        delta = max(0ll,delta);
        ll r = A[ptr-1]*(A[ptr-1]+1)/2-delta*(delta+1)/2;
        res = max(res,r+cnt);
    }
    cout<<res<<endl;
    return 0;
}