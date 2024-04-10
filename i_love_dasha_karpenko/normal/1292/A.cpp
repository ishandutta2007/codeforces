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
const ll DIM = 10E4+107;
const ll INF = 10E17;

ll A[2][DIM];
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,q; cin>>n>>q;
    ll flag = 0;
    forn(i,q){
        ll r,c; cin>>r>>c;
        r--;
        A[r][c]^=1;
        if (A[r][c]==0){
            flag-=A[r^1][c];
            flag-=A[r^1][c+1];
            flag-=A[r^1][c-1];
        }
        else{
            flag+=A[r^1][c];
            flag+=A[r^1][c+1];
            flag+=A[r^1][c-1];
        }
        if (flag==0)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}