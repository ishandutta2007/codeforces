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

const ll DIM = 2e5+7;
const ll INF = 2E18;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll A[DIM];
map<ll,ll> M;
vector<ll> V[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        set<ll> S;
        forn(i,n){
            cin>>A[i];
            S.insert(A[i]);
        }
        ll cnt = 0;
        for(ll to:S){
            M[to] = ++cnt;
        }
        forn(i,n){
            V[M[A[i]]].pb(i);
        }
        ll res = INF;
        forn(i,cnt){
            ll pre = ll(upper_bound(V[i-1].begin(),V[i-1].end(),V[i][0])-V[i-1].begin());
            pre+=V[i].size();
            while(i<cnt && V[i+1][0]>V[i].back()){
                pre+=V[i+1].size();
                ++i;
            }
            pre+=ll(V[i+1].size())-ll(lower_bound(V[i+1].begin(),V[i+1].end(),V[i].back())-V[i+1].begin());
            res = min(res,n-pre);
        }
        forn(i,cnt){
            ll c = 0;
            for(ll to:V[i]){
                ++c;
                ll l = ll(V[i+1].size())-ll(lower_bound(V[i+1].begin(),V[i+1].end(),to)-V[i+1].begin());
                res = min(res,n-l-c);
            }
        }
        cout<<res<<endl;
        forn(i,cnt)V[i].clear();
        M.clear();
    }

    return 0;
}
// 001011
// 001110
// 011010
// 110010
// 1110
// 11 - 8 11-8+1-3 = 1
// 11 10 8
// 1001100
// 4,3,2,6,