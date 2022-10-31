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
    ll t;
    cin>>t;

    while(t--){
        ll x,y,x1,y1;
        cin>>x>>y>>x1>>y1;
        ll d1 = x1-x;
        ll d2 = y1-y;
        if (d1<0 || d2<0){
            cout<<"0\n";
            continue;
        }
        ll vert;
        if (d2<=d1){
            vert = (d2+1)*d2/2;
        }
        else{
            vert = (d1+1)*d1/2+(d2-d1)*d1;
        }
        ll hor;
        swap(d1,d2);
        d2--;
        if (d2<=d1){
            hor = (d2+1)*d2/2;
        }
        else{
            hor = (d1+1)*d1/2+(d2-d1)*d1;
        }
        cout<<vert+hor+1<<endl;
    }
    return 0;
}