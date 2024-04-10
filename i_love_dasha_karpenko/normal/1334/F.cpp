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


const ll DIM = 5E5+7;
const ll INF = 2E18;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll A[DIM],cost[DIM],B[DIM],ss[DIM];
vector<ll> V[DIM];
vector<pp> dp,cur;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    forn(i,n){
        cin>>A[i];
    }
    forn(i,n){
        cin>>cost[i];
    }
    ll m;
    cin>>m;
    forn(i,m){
        cin>>B[i];
    }
    B[m+1] = INF;
    A[n+1] = INF;
    forn(i,n+1){
        ll pos = lower_bound(B,B+2+m,A[i])-B;

        if (cost[i]<0)
        ss[pos]+=cost[i];
        V[pos].pb(i);
    }
    //cout<<endl;
    dp.pb({0,0});

    for(ll el = 1;el<=m+1;++el){
        ll sum = 0;
        ll num = B[el];
       // reverse(V[el].begin(),V[el].end());
        ll mi = 0;
        ll si = 0;
        ll flag = 0;
        for(ll to:V[el]){
            while(!dp.empty() && dp.back().fi<to){
                if (flag==0)
                    mi = dp.back().sc;
                flag = 1;

                mi = min(mi,dp.back().sc);
                dp.pop_back();
            }
            sum+=cost[to];
            if (cost[to]<0){
                ss[el]-=cost[to];
            }
            if (A[to]==num && flag){
                cur.pb({to,mi-cost[to]+ss[el]+sum});

            }


        }

        swap(dp,cur);
        reverse(dp.begin(),dp.end());
        cur.clear();

    }
    if (dp.size()==0){
        cout<<"NO\n";

    }

    else if (dp.size()==1){
        cout<<"YES\n";

        cout<<dp[0].sc<<endl;
    }
    return 0;
}
// 1110
// 11 - 8 11-8+1-3 = 1
// 11 10 8
// 1001100
// 4,3,2,6,