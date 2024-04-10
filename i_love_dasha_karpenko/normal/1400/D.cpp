#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 3000+7;
const ll INF = 1E17;
const ll MAXN = 1E6;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
ll A[DIM];
ll nxt[DIM][DIM];
ll sto[DIM],bef[DIM];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        forn(i,n){
            cin>>A[i];
        }
        for(ll i = n;i>=1;--i){
            forn(j,n){
                nxt[i][j] = nxt[i+1][j];
            }
            nxt[i][A[i+1]]++;
        }
        ll res = 0;

        forn(i,n){
            ll cnt = 0;
            forn(j,n)sto[j] = nxt[i][j];
            for(ll j = i+1;j<=n;++j){
                cnt-=bef[A[j]];
                sto[A[j]]--;


                if (A[i]==A[j])res+=cnt;
                bef[A[j]]++;
                cnt+=sto[A[j]];
            }
            forn(j,n)sto[j] = bef[j] = 0;
        }
        cout<<res<<endl;
        forn(i,n){
            A[i] = 0;
            forn(j,n){
                nxt[i][j] = 0;
            }
        }

    }
    return 0;
}