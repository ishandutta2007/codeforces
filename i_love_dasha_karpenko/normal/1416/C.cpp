#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef int ll;
typedef tree<pair<ll,ll>,null_type,less<pair<ll,ll> >,rb_tree_tag,tree_order_statistics_node_update> super_set;
#define x1 gdsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 3E5+7;
const ll INF = 1E18;
ll A[DIM];
ll T[DIM];
pair<ll,ll> V[DIM];
ll n;
ll add(ll pos,ll delta){
    for(ll i = pos;i<=n;i+=i&-i)T[i]+=delta;
}
ll get(ll pos){
    ll ret = 0;
    for(ll i = pos;i>=1;i-=i&-i)ret+=T[i];
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    cin>>n;
    ll mx = 0;
    for(ll i = 1;i<=n;++i){
        cin>>A[i];
        mx = max(mx,A[i]);
    }
    long long x = 0;
    long  mult = 1;
    while(mult*2<=mx)mult*=2;
    long  mask = mult;
    while(mult>0){
        long long cnt = 0;
        ll base = x;
        x^=mult;
        {


            for(ll i = 1;i<=n;++i){
                ll val = A[i];
                V[i] = {val^x,i};
                T[i] = 0;
            }
            sort(V+1,V+1+n);
            ll past = 0;
            for(ll i = 1;i<=n;++i){
                auto to = V[i];
                cnt+=past-get(to.second);
                ++past;
                add(to.second,1);
            }

        }
        long long cnt1 = cnt;
        cnt = 0;
        x^=mult;
        {
            for(ll i = 1;i<=n;++i){
                ll val = A[i];
                V[i] = {val^x,i};
                T[i] = 0;
            }
            sort(V+1,V+1+n);
            ll past = 0;
            for(ll i = 1;i<=n;++i){
                auto to = V[i];
                cnt+=past-get(to.second);
                ++past;
                add(to.second,1);
            }
        }
        if (cnt1<cnt)x^=mult;
        mult = mult>>1;
        mask^=mult;
    }


    long long cnt = 0;
    for(ll i = 1;i<=n;++i){
                ll val = A[i];
                V[i] = {val^x,i};
                T[i] = 0;
            }
            sort(V+1,V+1+n);
            ll past = 0;
            for(ll i = 1;i<=n;++i){
                auto to = V[i];
                cnt+=past-get(to.second);
                ++past;
                add(to.second,1);
            }
   // cout<<mask<<endl;
    cout<<cnt<<' '<<x<<endl;
    return 0;
}