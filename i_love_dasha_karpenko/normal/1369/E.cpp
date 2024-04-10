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

const ll DIM = 2E5+7;
const ll INF = 2E18;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll n,m,w[DIM];
pp A[DIM];
set<ll> V[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    forn(i,n)cin>>w[i];
    forn(i,m){
        cin>>A[i].fi>>A[i].sc;
        V[A[i].fi].insert(i);
        V[A[i].sc].insert(i);
    }
    set<pp> S;
    forn(i,n){
        S.insert({V[i].size()-w[i],i});
    }
    vector<ll> ans;
    while(!S.empty()){
        pp to = *S.begin();
        S.erase(S.begin());
        if (to.fi>0){
            cout<<"DEAD\n";
            return 0;
        }

        for(ll pos:V[to.sc]){
            ans.pb(pos);
            ll el = to.sc^A[pos].fi^A[pos].sc;
            S.erase({V[el].size()-w[el],el});
            V[el].erase(pos);
            S.insert({V[el].size()-w[el],el});
        }
    }
    cout<<"ALIVE\n";
    while(!ans.empty()){
        cout<<ans.back()<<' ';
        ans.pop_back();
    }
    return 0;
}
// (i-1)%p
// l = A[i],r = A[i+1]
// 001011
// 001110
// 011010
// 110010
// 1110
// 11 - 8 11-8+1-3 = 1
// 11 10 8
// 1001100
// 4,3,2,6,