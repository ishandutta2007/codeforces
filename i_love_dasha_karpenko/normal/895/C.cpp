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

const ll DIM = 1E5+7;
const ll MOD = 1e9+7;
const ll INF = 2E18;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
const ll masksz = po(19);
const ll MAXN = 71;
ll sm[MAXN];
vector<ll> simp;

ll ways[DIM],msk[MAXN],cnt[MAXN],dp[masksz],olddp[masksz];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(ll i = 2;i<MAXN;++i){
        if (sm[i])continue;
        simp.pb(i);
        for(ll j = i*i;j<MAXN;j+=i)sm[j] = 1;
    }
    ll n;
    cin>>n;
    ways[1] = 1;
    ways[0] = 1;
    for(ll i = 2;i<=n;++i){
        ways[i] = (ways[i-1]*2)%MOD;
    }
    forn(i,n){
        ll x;
        cin>>x;
        ll st = x;
        ll mask = 0;
        ll mult = 1;
        for(ll to:simp){
            ll ct = 0;
            while(x%to==0){
                x/=to;
                ++ct;
            }
            mask+=mult*(ct&1);
            mult*=2;
        }
        msk[st] = mask;
        cnt[st]++;
    }
    olddp[0] = 1;
    forn(i,MAXN-1){
        for(ll mask = 0;mask<masksz;++mask){
            dp[mask] = (olddp[mask]*ways[cnt[i]])%MOD;
            if (cnt[i]!=0)dp[mask] = (dp[mask]+(olddp[mask^msk[i]]*ways[cnt[i]])%MOD)%MOD;
        }
        for(ll mask = 0;mask<masksz;++mask){
            olddp[mask] = dp[mask];
        }
    }
    cout<<(olddp[0]+MOD-1)%MOD<<endl;
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