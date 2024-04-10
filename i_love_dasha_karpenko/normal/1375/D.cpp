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

const ll DIM = 1000+7;
const ll INF = 2E18;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll A[DIM];
ll n;
ll calc(){
    set<ll> S;
    forn(i,n)S.insert(A[i]);
    ll ptr = 0;
    for(ll to:S){
        if (to==ptr)++ptr;
    }
    return ptr;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){

        cin>>n;
        ll flag = 0;
        forn(i,n){
            cin>>A[i];
            if (A[i]==0)flag = 1;
        }
        vector<ll> ans;
        A[n+1] = n;
        for(ll i = n;i>=1;--i){
            //if (A[i]==i-1)continue;

            while(A[i]!=i-1){
                    ll mex = calc();
                    while(mex<i-1){
                        A[mex+1] = mex;
                        ans.pb(mex+1);
                        mex = calc();
                    }

                        ans.pb(i);
                        A[i] = mex;
            }
           // cout<<A[i]<<' ';
        }
       // cout<<endl;


        cout<<ans.size()<<endl;
        for(ll to:ans)cout<<to<<' ';
        cout<<endl;
        ans.clear();

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