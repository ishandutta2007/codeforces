#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

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

const ll INF = 1E16+7;
const ld eps = 0.00000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution <int> (a, b)(rng);
}
struct node{
    ll w,u,v;
};
vector<node> edges;
ll A[DIM],B[DIM];
bool mc(node a,node b){
    return a.w>b.w;
}
ll P[DIM];
ll F(ll x){
    if (x==P[x])return x;
    return P[x] = F(P[x]);
}
ll unite(ll x,ll y){
    x = F(x);
    y = F(y);
    if (x==y)return 0;
    if (rand()%2)swap(x,y);
    P[x] = y;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>m>>n;
    forn(i,m)cin>>A[i];
    forn(i,n)cin>>B[i];
    forn(i,n+m)P[i] = i;
    ll sum = 0;
    forn(i,m){
        ll sz;
        cin>>sz;
        while(sz--){
            ll x;
            cin>>x;
            edges.pb({A[i]+B[x],x,i+n});
            sum+=A[i]+B[x];
        }
    }
    sort(edges.begin(),edges.end(),mc);
    for(node to:edges){
        if (unite(to.u,to.v))sum-=to.w;
    }
    cout<<sum<<endl;



    return 0;
}