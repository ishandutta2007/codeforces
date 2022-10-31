#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1ll;i<=n;++i)
#define pb push_back
#define endl '\n'
#define po(x) (1ll<<x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less<pp>,rb_tree_tag,tree_order_statistics_node_update> satan_set;
const ll DIM = 5*10E4+7;
const ll INF = 10E16;
const ll MAXN = 10E4+1;
struct node{
    ll fi,sc,pos;
};
ll n,can[DIM],cnt = 0;
node A[DIM];
vector<ll> G[DIM];
const bool operator<(const node &a,const node &b){
    if (a.fi==b.fi)return a.sc<b.sc;
    return a.fi<b.fi;
}
void dfs(ll v,ll par){
    if (can[v]==1){
        cout<<"NO\n";
        exit(0);
    }
    can[v] = 1;
    cnt++;
    for(ll to:G[v])if (to!=par)dfs(to,v);
}
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    if (n==1ll){
        cout<<"YES\n";
        return 0;
    }
    forn(i,n){
        cin>>A[i].fi>>A[i].sc;
        can[i] = 0;
    }
    sort(A+1,A+1+n);
    ll p = 1,edges = 0;
    satan_set S;

    forn(i,n){
        S.insert({A[i].sc,i});
        while(S.begin()->fi<A[i].fi)S.erase(S.begin());
        p = S.order_of_key({A[i].sc,-INF});
        edges+=p;
        /*for(pp to:S){
            if (to.sc==i)break;
                G[to.sc].pb(i);
                G[i].pb(to.sc);

        }*/
        //if (p>=1ll)can[i] = 1ll;
        A[i].pos = i;
        if (S.size()==1 && i!=1){
            cout<<"NO\n";
            return 0;
        }
        //cout<<S.size()<<endl;
    }
    if (edges!=n-1)return cout<<"NO\n",0;
    S.clear();
    forn(i,n){
        S.insert({A[i].sc,i});
        while(S.begin()->fi<A[i].fi)S.erase(S.begin());
        p = S.order_of_key({A[i].sc,-INF});
        edges+=p;
        for(pp to:S){
            if (to.sc==i)break;
                G[to.sc].pb(i);
                G[i].pb(to.sc);

        }
        //if (p>=1ll)can[i] = 1ll;
        A[i].pos = i;
        if (S.size()==1 && i!=1){
            cout<<"NO\n";
            return 0;
        }
        //cout<<S.size()<<endl;
    }
    dfs(1,-1);
    if (cnt==n)
    cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}

// 1 2 3
//