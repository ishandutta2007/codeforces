#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 10E4 +7;
const ll INF = 10E17;

ll n,A[DIM],cnt[60];
ll F(ll a,ll b){
    return (a|b)-b;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n){
        cin>>A[i];
        ll x = A[i],bit = 0;
        while(x>0){
            if (x&1){
                cnt[bit]++;
            }
            x/=2;
            bit++;
        }
    }
    pp st = {-INF,0};
    forn(i,n){
        ll x = A[i],bit = 0,res = 0;
        while(x>0){
            if (x&1 && cnt[bit]==1){
                res+=po(bit);
            }
            x/=2;
            bit++;
        }
        if (res>st.fi){
            st.fi = res;
            st.sc = i;
        }
    }
    swap(A[1],A[st.sc]);
    forn(i,n)cout<<A[i]<<' ';
    cout<<endl;
    return 0;
}