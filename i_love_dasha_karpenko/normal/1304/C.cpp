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
const ll DIM = 1000+7;
const ll INF = 10E17;
struct node{
    ll t,l,r;
};
node A[DIM];
bool mc(node a,node b){
    return a.t<b.t;
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll te;
    cin>>te;
    while(te--){
        ll n,m;
        cin>>n>>m;
        forn(i,n){
            cin>>A[i].t>>A[i].l>>A[i].r;
        }
        sort(A+1,A+1+n,mc);
        ll l = m,r = m,last = 0,flag = 0;
        forn(i,n){
            ll d = A[i].t-last;
            ll tl = l-d;
            ll tr = r+d;
            if (A[i].l>tr || tl>A[i].r){
                cout<<"NO\n";
                flag = 1;
                break;
            }
            l = max(tl,A[i].l);
            r = min(tr,A[i].r);
            last = A[i].t;
        }
        if (flag==1)continue;
        cout<<"YES\n";
    }
    return 0;
}