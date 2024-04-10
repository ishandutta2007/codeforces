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

const ll DIM = 5000+7;
const ll INF = 1E19;
const ll MAXN = 1E6;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll a,b,x,y;
        cin>>a>>b>>x>>y;
        ll n;
        cin>>n;
        ll res = INF;
        ll a1 = a,b1 = b;
        ll n1 = n;
        ll g = min(n,a-x);
        a-=g;
        n-=g;
        g = min(n,b-y);
        b-=g;
        res = min(res,a*b);
        a = a1;
        b = b1;
        n = n1;
        swap(a,b);
        swap(x,y);
        g = min(n,a-x);
        a-=g;
        n-=g;
        g = min(n,b-y);
        b-=g;
        res = min(res,a*b);
        cout<<res<<endl;

    }
    return 0;
}