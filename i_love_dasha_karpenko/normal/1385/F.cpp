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
ll cnt[DIM];
set<ll> G[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll ttt;
    cin>>ttt;
    while(ttt--){
        ll n,k;
        cin>>n>>k;
        forn(i,n-1){
            ll x,y;
            cin>>x>>y;
            G[x].insert(y);
            G[y].insert(x);
        }
        vector<ll> V;
        forn(i,n){
            if (G[i].size()==1){
                V.pb(i);
            }
        }
        ll res = 0;
        while(!V.empty()){
            ll t = V.back();
            V.pop_back();
            if (G[t].empty())continue;
            cnt[*G[t].begin()]++;
            G[*G[t].begin()].erase(t);
            res+=cnt[*G[t].begin()]/k;
            cnt[*G[t].begin()]%=k;
            if (cnt[*G[t].begin()]==0 && G[*G[t].begin()].size()==1)V.pb(*G[t].begin());
        }
        cout<<res<<endl;
        V.clear();
        forn(i,n){
            G[i].clear();
            cnt[i] = 0;
        }


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