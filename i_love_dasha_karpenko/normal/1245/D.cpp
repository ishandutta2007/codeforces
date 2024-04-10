#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
const ll DIM = 2007;
const ll INF = 10E17;
const ll MOD = ll(1000000007) ;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
#define x1 Artem
#define y1 Pidor
const ll LOG = 9;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> my_super_set;
struct node{
    ll fi,sc,th;
};
bool const operator<(const node &a,const node &b){
    if (a.fi==b.fi)return a.sc<b.sc;
    return a.fi<b.fi;
}
ll n,C[DIM],K[DIM],P[DIM],vis[DIM];
pp cost[DIM];
node A[DIM];
ll F(ll x){
    if (x==P[x])return x;
    return P[x] = F(P[x]);
}
ll Check(ll a,ll b){
    a=  F(a); b = F(b);
    return a==b;
}
void unite(ll a,ll b){
    a = F(a); b = F(b);
    if (rand()%2){
        P[a] = b;
        if (cost[a].fi<cost[b].fi){
            cost[b] =cost[a];
        }
        else{
            cost[a]= cost[b];
        }
    }
    else{
        P[b] = a;
        if (cost[a].fi<cost[b].fi){
            cost[b] =cost[a];
        }
        else{
            cost[a]= cost[b];
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    forn(i,n){
        P[i] = i;
    cin>>A[i].fi>>A[i].sc;
    A[i].th = i;
    }
    //sort(A+1,A+1+n);

    forn(i,n){
        cin>>C[i];
        ll start = 0,mi = INF;
        if (C[i]<mi){
            mi = C[i];
            start = i;
        }
        cost[i] = {C[i],i};
    }
    forn(i,n){

    cin>>K[i];

    }
    ll res = 0;
    vector<pp> ans;
    vector<node> vec;
    forn(i,n){
        forn(j,n){
            vec.pb({(abs(A[j].fi-A[i].fi)+abs(A[j].sc-A[i].sc))*(K[i]+K[j]),i,j});
        }
        //

    }
    sort(vec.begin(),vec.end());
    for(node to:vec){
        ll x = F(to.sc),y = F(to.th);
        if (x!=y && (cost[x].fi>to.fi || cost[y].fi>to.fi)){
            unite(to.sc,to.th);
            ans.pb({to.sc,to.th});
            res+=to.fi;

        }
    }
    vector<ll> ans1;
    forn(i,n){
        if (vis[F(i)]==0){
            ans1.pb(cost[F(i)].sc);
            res+=cost[F(i)].fi;
            vis[F(i)] = 1;
        }
    }
    cout<<res<<endl;
    cout<<ans1.size()<<endl;
    for(ll to:ans1)cout<<to<<' ';
    cout<<endl;
    cout<<ans.size()<<endl;
    for(pp to:ans)cout<<to.fi<<' '<<to.sc<<endl;
    cout<<endl;
    return 0;
}