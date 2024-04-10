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
const ll MOD = 1e9+7;
const ll INF = 1E17;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll A[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll n = s.length();
        for(ll i = 0;i<s.length();++i){
            A[i+1] = s[i]-'0';
        }
        ll res = n;
        for(ll a = 0;a<=9;++a){
            for(ll b = 0;b<=9;++b){
                ll r = 0;
                ll flag = 0;
                ll rn = INF;
                forn(i,n){
                    if (flag==0 && A[i]!=a)++r;
                    else if (flag==0){
                        flag^=1;
                        continue;
                    }
                    if (flag==1 && A[i]!=b)++r;
                    else if (flag==1){
                        flag^=1;
                        rn = min(rn,r+(n-i));
                    }
                }
                res = min(res,rn);
            }
            ll r = 0;
            forn(i,n){
                if (A[i]!=a)++r;
            }
            res = min(res,r);
        }
        cout<<res<<endl;
    }


    return 0;
}