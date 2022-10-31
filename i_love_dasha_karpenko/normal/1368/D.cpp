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
const ll INF = 2E15;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll A[DIM],cnt[DIM][30],surp[30];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;

    forn(i,n)cin>>A[i];
    for(ll i = n;i>=1;--i){
        ll x = A[i];
        for(ll bit = 0;bit<30;++bit){
            cnt[i][bit] = cnt[i+1][bit];
            if (x&1)++cnt[i][bit];
            x/=2;
        }
    }
    ll res = 0;
    forn(i,n){
        ll mult = 1;
        ll num = 0;
        for(ll bit = 0;bit<30;++bit){
            cnt[i][bit]-=surp[bit];
            if (cnt[i][bit]>0){
                num+=mult;
                ++surp[bit];
            }
            mult*=2;
        }
        res+=num*num;
        ll x = A[i];
        for(ll bit = 0;bit<30;++bit){
            if (x&1)--surp[bit];
            x/=2;
        }
    }
    cout<<res<<endl;
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