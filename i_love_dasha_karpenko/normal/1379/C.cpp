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

const ll INF = 2E18;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

pp A[DIM];
ll pref[DIM];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;

        forn(i,m){
            cin>>A[i].fi>>A[i].sc;
        }
        sort(A+1,A+1+m);

        for(ll i = m;i>=1;--i){
            pref[i] = pref[i+1]+A[i].fi;
        }
        ll res = 0;
        forn(i,m){
            ll pos = (upper_bound(A+1,A+1+m,pp{A[i].sc,-INF})-A);
            pos = max(pos,m-n+1);
            ll r = pref[pos];
            ll mm = n-(m-pos+1);
            if (mm>0 && pos>i){
                r+=A[i].fi;
                mm--;
            }
            r+=mm*A[i].sc;
            res = max(res,r);
        }


        cout<<res<<endl;
        forn(i,m)pref[i] = 0;
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