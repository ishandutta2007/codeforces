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

const ll DIM = 3E5+7;
const ll INF = 1E17;
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
        ll p,f;
        cin>>p>>f;
        ll a,b;
        cin>>a>>b;
        ll s,w;
        cin>>s>>w;
        ll res = 0;
        for(ll i = 0;i<=a;++i){
            if (i*s>p)break;
            ll g = min(b,(p-i*s)/w);
            ll da = 0,db = 0;
            b-=g;
            db+=g;
            ll r = g+i;
            if (s<w){
                g = min(a-i,f/s);
                r+=g;
                r+= min(b,(f-g*s)/w);
            }
            else{
                g = min(b,f/w);
                r+=g;
                r+= min(a-i,(f-g*w)/s);
            }
            b+=db;
            res = max(res,r);
        }
        cout<<res<<endl;
    }
    return 0;
}