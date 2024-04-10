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
#define x1 dsfdsfes
#define y1 sfsdfdse
#define po(x) (1ll<<x)
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;
const ll DIM = 3*10E4+107;
const ll INF = 10E17;
const ll MAXN = DIM-5;
struct node{
    ll fi,sc,th;
};
ll last[DIM],A[DIM*2],mi[DIM],mx[DIM];

int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for(ll i = m+1;i<=m+n;++i){
        A[i] = i-m;
        mi[i-m] = mx[i-m] = i-m;
    }
    for(ll i = m;i>=1;--i){
        cin>>A[i];
        mi[A[i]] = 1;
    }
    super_set S;
    memset(last,-1,sizeof(last));
    forn(i,n+m){
        ll bef;
        if (last[A[i]]==-1)bef = S.size();
        else
            bef = S.order_of_key({i,-INF})-S.order_of_key({last[A[i]],INF});
        mx[A[i]] = max(mx[A[i]],bef+1);
        if (last[A[i]]!=-1){
            S.erase({last[A[i]],A[i]});
        }
        S.insert({i,A[i]});
        last[A[i]] = i;
        //cout<<S.size()<<endl;
    }
    forn(i,n){
        cout<<mi[i]<<' '<<mx[i]<<endl;
    }
    return 0;
}