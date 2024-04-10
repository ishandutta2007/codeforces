#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> satan_set;
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define fi first
#define sc second
#define x1 dsfdsf
#define y1 fgdfgdfg
#define endl '\n'
const ll DIM = 5000+7;
const ll INF = 10e16;
const ll MOD = 998244353 ;
const ll MAXN = 1000000000;
ll A[DIM],B[DIM],C[DIM],pref[DIM];
ll par[DIM];
vector<ll> child[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,k; cin>>n>>m>>k;
    ll s = 0;
    forn(i,n){
        cin>>A[i]>>B[i]>>C[i];
        s+=C[i];
    }
    //cout<<s<<endl;
    forn(i,m){
        ll x,y; cin>>x>>y;
        par[y] = max(par[y],x);
    }
    ll res = 0,money = k;
    forn(i,n){
        pref[i-1] = money-A[i];
        money+=B[i];
        if (pref[i-1]<0){
            cout<<"-1\n";
            return 0;
        }
    }
    pref[n] = money;
    ll suf = INF;
    for(ll i = n;i>=1;i--){
        suf = min(suf,pref[i]);
        pref[i] = suf;
    }

    //cout<<endl;
    priority_queue<ll,vector<ll>,greater<ll> > Q;
    ll sum = 0;
    forn(i,n){
        if (par[i]>i){
            child[par[i]].pb(i);
        }
        else{
            Q.push(C[i]);
            sum+=C[i];
        }
        for(ll to:child[i]){
            Q.push(C[to]);
            sum+=C[to];
        }
        while(Q.size()>pref[i]){
            sum-=Q.top();
            Q.pop();
        }
        //cout<<Q.size()<<' ';
       // cout<<sum<<' ';
    }
    cout<<sum<<endl;
    return 0;

}