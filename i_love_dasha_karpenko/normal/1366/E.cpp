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

const ll DIM = 2E5+7;
const ll INF = 1E10;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
const ll MOD = 998244353;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

ll A[DIM],B[DIM],st[DIM],last[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    forn(i,n){
        cin>>A[i];
    }
    forn(i,m){
        cin>>B[i];
    }
    ll mi = INF;
    ll cur = m;
    for(ll i = n;i>=0;--i){
        mi = min(mi,A[i]);

        while(B[cur]>mi){
            st[cur] = i+1;
            --cur;
        }
        if (last[cur]==0 && A[i]==B[cur])last[cur] = i;
    }
    if (st[1]!=1 || last[1]==0){
        cout<<0<<endl;
        return 0;
    }
    ll res = 1;
    for(ll i = 2;i<=m;++i){
        if (last[i]==0){
            cout<<0<<endl;
            return 0;
        }
        res=(res*(last[i]-st[i]+1))%MOD;
    }
    cout<<res<<endl;
    return 0;
}