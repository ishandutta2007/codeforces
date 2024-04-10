#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long  ll;
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
const ll DIM2 = 1E6+7;
const ll INF = 1E17;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}


ll A[DIM],B[DIM],vis[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;
    set<ll> S;
    for(ll i = 0;i<=n;++i)S.insert(i);
    forn(i,n){
        cin>>A[i];
        S.erase(A[i]);
    }
    memset(B,-1,sizeof(B));




    forn(i,n){
        B[i] = *S.begin();
        S.erase(*S.begin());
        if (A[i]!=A[i+1])
        S.insert(A[i]);
    }
    memset(vis,0,sizeof(vis));
    ll ptr = 0;
    forn(i,n){
        if (B[i]<DIM)
        vis[B[i]] = 1;
        while(vis[ptr]==1)++ptr;
        if (A[i]!=ptr){
            cout<<-1<<endl;
            return 0;
        }
    }
    forn(i,n){
        cout<<B[i]<<' ';
    }
    cout<<endl;

    return 0;
}