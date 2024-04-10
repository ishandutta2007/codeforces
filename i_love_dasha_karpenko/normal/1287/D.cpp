#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 2000  +7;
const ll INF = 10E10;
ll A[DIM],val[DIM];
ll pos = 0,flag = 0;
vector<ll> G[DIM];
dfs(ll v,satan_set &S){
    if (A[v]+1>S.size()){
        flag = 1;
    }
    auto it = S.find_by_order(A[v]);

    ll p = *it;
    S.erase(it);
    val[v] = p;
    for(ll to:G[v]){
        dfs(to,S);
    }
    if (S.order_of_key(val[v])!=0){
        cout<<"NO\n";
        exit(0);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll root = 0;
    ll n; cin>>n;
    forn(i,n){
        ll x; cin>>x>>A[i];
        if (x==0)root = i;
        G[x].pb(i);

    }
    satan_set S;
    forn(i,n)S.insert(i);
    dfs(root,S);
    if (flag==1){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    forn(i,n)cout<<val[i]<<' ';
    cout<<endl;
    return 0;
}