#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long  ll;
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
#define log sdfdsfdsf

const ll DIM = 5000+7;
const ll INF = 1E17;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll ct[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,d;
        cin>>n>>d;
        ll mx = n*(n-1)/2;
        ll cnt = n-1;
        ll last = 1;
        ll mi = 0;
        for(ll lev = 1;cnt>0;++lev){
            last*=2;
            ll g = min(cnt,last);
            cnt-=g;
            mi+=g*lev;
        }
        if (mi<=d && d<=mx){
            cout<<"YES\n";
            forn(i,n)ct[i] = 1;
            while(mx>d){
                last = 0;
                for(ll i = n;i>2;--i){
                    if (ct[i]>0 && ct[i-2]*2>=ct[i-1]+1 && ct[i]*2-2>=ct[i+1]){
                        last = i;
                    }
                }
                --ct[last];
                ++ct[last-1];
                --mx;
            }

            ll ptr = 1;
            for(ll i = 2;i<=n;++i){
                ll prev = ptr;
                for(ll j = 1;j<=ct[i];++j){
                    cout<<prev<<' ';
                    if (j%2==0)++prev;
                }
                ptr+=ct[i-1];
            }
            cout<<endl;
        }
        else{
            cout<<"NO\n";
        }
        forn(i,n)ct[i] = 0;

    }
    return 0;
}