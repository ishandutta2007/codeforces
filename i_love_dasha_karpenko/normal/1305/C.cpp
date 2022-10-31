#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef int ll;
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
const ll DIM = 2*10E4+7;
const ll INF = 10E16;
const ll MM = 2007;
ll A[DIM],cnt[MM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    ll n,m;
    cin>>n>>m;
    //ll cnt = 0;
    forn(i,n){
        cin>>A[i];
        ll g = A[i]%m+m;
        cnt[g]++;
    }
    sort(A+1,A+1+n);

    ll res = 1;

    forn(i,n){
        cnt[A[i]%m+m]--;
        if (i<n && A[i]==A[i+1]){
            cout<<0<<endl;
            return 0 ;
        }
        for(ll j = m;j<=m*2;j++){
            if (cnt[j]==0)continue;
            res = (((j-A[i]%m)*cnt[j])*res)%m;
        }
    }
    cout<<res<<endl;

    return 0;
}