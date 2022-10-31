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
ll A[DIM];
ll gi(char ch){
    return ch-'a'+1;
}
ll pref[DIM][30];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        forn(i,n){
            char ch;
            cin>>ch;
            A[i] = gi(ch);
        }
        forn(i,n){
            forn(j,26)pref[i][j] = pref[i-1][j];
            ++pref[i][A[i]];
        }
        ll lg = 0;
        ll x = n;
        while(x){
            x/=2;
            ++lg;
        }
        ll res = INF;
        forn(i,n){
            ll st = i,len = 1;
            ll symb = lg;
            ll r = 0;
            ll prev = st;
            while(len<=n){
                if (len<=1)
                r+=len-pref[st+len-1][symb]+pref[st-1][symb];
                else{
                    if (prev==st){
                        r+=len/2-pref[st+len-1][symb]+pref[st+len/2-1][symb];
                    }
                    else{
                        r+=len/2-pref[st+len/2-1][symb]+pref[st-1][symb];
                    }
                }
                len*=2;
                prev = st;
                if ((st+len-1)%len!=0)st-=len/2;
                --symb;
            }
            res = min(res,r);

        }

        cout<<res<<endl;
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