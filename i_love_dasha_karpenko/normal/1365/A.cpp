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
const ll DIM = 100+7;
const ll INF = 1E16;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll A[DIM][DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll cnt = 0;
        forn(i,n){
            forn(j,m){
                cin>>A[i][j];
            }
        }
        ll cnt1 = 0,cnt2 = 0;
        forn(i,n){
            ll flag = 0;
            forn(j,m){

                if (A[i][j]==1){
                    flag = 1;
                    break;
                }
            }
            if (flag==0)cnt1++;
        }

        forn(j,m){
            ll flag = 0;
            forn(i,n){
                if (A[i][j]==1){
                    flag = 1;
                    break;
                }
            }
            if (flag==0)cnt2++;
        }
        if (min(cnt1,cnt2)%2==0)cout<<"Vivek\n";
        else cout<<"Ashish\n";
    }

    return 0;
}