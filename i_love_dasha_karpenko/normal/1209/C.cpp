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
const ll DIM = 2*10E4+7;
const ll INF = 10E17;

ll A[DIM],vis[DIM];
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll te;
    cin>>te;
    forn(qe,te){
        ll n;
        cin>>n;
        vector<pp> V;

        forn(i,n){
            char ch;
            cin>>ch;
            A[i] = ch-'0';
            vis[i] = 0;
            if (V.empty() || A[i]>=V.back().fi)V.pb({A[i],i});
            else{
                while(!V.empty() && V.back().fi>A[i])V.pop_back();
                V.pb({A[i],i});
            }
        }

        for(pp to:V)vis[to.sc] = 1;
        ll last = -INF,flag = 0;
        forn(i,n){
            if (vis[i]==1)continue;
            while(!V.empty() && A[i]<V.back().fi){
                vis[V.back().sc] = 0;
                V.pop_back();
            }
        }
        forn(i,n){
            if (vis[i]==1)continue;
            if (A[i]<V.back().fi || A[i]<last){
                flag = 1;
                break;
            }
            last = A[i];
        }
        if (flag==1){
            cout<<"-\n";
            continue;
        }
        forn(i,n){
            cout<<2-vis[i];
        }
        cout<<endl;
    }
    return 0;
}