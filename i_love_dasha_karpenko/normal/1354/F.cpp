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
#define log sdfdsfdsf

const ll DIM = 75+7;
const ll INF = 2E9;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
struct node{
    ll fi,sc,pos;
};
ll dp[DIM][DIM];
pp P[DIM][DIM];
node A[DIM];
bool mc(node a,node b){
    if (a.fi==b.fi)return a.sc<b.sc;
    return a.fi<b.fi;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll sum = 0;
        forn(i,n){
            cin>>A[i].sc>>A[i].fi;
            A[i].pos = i;
            sum+=(k-1)*A[i].fi;
        }
        sort(A+1,A+1+n,mc);

        dp[0][0] = sum;

        forn(i,n){
            for(ll sz = 1;sz<=min(k,i);++sz){
                for(ll prev = 0;prev<=i-1;++prev){
                    if (dp[i][sz]<dp[prev][sz-1]+A[i].sc-A[i].fi*(k-sz)){
                        dp[i][sz]=dp[prev][sz-1]+A[i].sc-A[i].fi*(k-sz);
                        P[i][sz] = {prev,sz-1};
                    }
                }
            }
        }
        ll mx = 1;
        forn(i,n)
            if (dp[i][k]>dp[mx][k])mx = i;
        pp st = {mx,k};
        vector<ll> ans;
        set<ll> S;
        forn(i,n)S.insert(i);
        while(st!=pp{0,0}){
            ans.pb(A[st.fi].pos);
            S.erase(st.fi);
            st = P[st.fi][st.sc];
        }
        reverse(ans.begin(),ans.end());
        cout<<k+(n-k)*2<<endl;
        for(ll i = 0;i<ans.size()-1;++i)cout<<ans[i]<<' ';
        for(ll to:S){
            cout<<A[to].pos<<' ';
            cout<<-A[to].pos<<' ';
        }
        cout<<ans.back()<<endl;
        forn(i,n){
            for(ll sz = 0;sz<=min(k,i);++sz)dp[i][sz] = 0;
        }
    }



    return 0;
}
// 1110
// 11 - 8 11-8+1-3 = 1
// 11 10 8
// 1001100
// 4,3,2,6,