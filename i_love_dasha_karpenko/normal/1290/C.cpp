#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
const ll DIM = 3*10E4 +7;
const ll INF = 10E17;

ll n,k,A[DIM],P[DIM*2],top[DIM*2],cnt[DIM*2][2],half[DIM],res = 0,nes[DIM*2][2];
void del(ll x){
    if (nes[x][0]==1)res-=cnt[x][0];
    else if (nes[x][1]==1)res-=cnt[x][1];
    else res-=min(cnt[x][0],cnt[x][1]);
}
void add(ll x){
    if (nes[x][0]==1)res+=cnt[x][0];
    else if (nes[x][1]==1)res+=cnt[x][1];
    else res+=min(cnt[x][0],cnt[x][1]);
}
ll F(ll x){
    if (x==P[x])return x;
    ll root = F(P[x]);
    half[x] = half[P[x]]^top[x];
    P[x] = root;
    top[x] = half[root]^half[x];
    return root;
}
void unite(ll a,ll b,ll mod){
    if (rand()%2)swap(a,b);
    ll x = F(a);
    ll y = F(b);
    if (x==y)return;
    del(x);
    del(y);
    if (half[a]!=half[b])mod^=1;
    P[y] = x;
    top[y] = mod;
    cnt[x][0]+=cnt[y][mod];
    cnt[x][1]+=cnt[y][mod^1];
    nes[x][0] = max(nes[x][0],nes[y][mod]);
    nes[x][1] = max(nes[x][1],nes[y][mod^1]);
    add(x);
}
vector<ll> G[DIM];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    forn(i,n){
        char ch;
        cin>>ch;
        A[i] = ch-'0';
    }
    forn(i,k){
        ll l;
        cin>>l;
        forn(j,l){
            ll x;
            cin>>x;
            G[x].pb(i);
        }
    }
    forn(i,k*2)P[i] = i;
    forn(i,k){
        cnt[i][0] = 1;
        P[i+k] = i;
        top[i+k] = 1;
    }
    forn(i,n){
        if (A[i]==0 && G[i].size()==0)n/=0;
        /*if (n==150000 && (i==4 || i==3)){
                ll a = F(G[i][0]);
                ll b = F(G[i][1]);
                cout<<G[i].size()<<endl<<a<<' '<<b<<endl;
                cout<<cnt[a][0]<<' '<<cnt[a][1]<<' '<<nes[a][0]<<' '<<nes[a][1]<<endl;
                cout<<cnt[b][0]<<' '<<cnt[b][1]<<' '<<nes[b][0]<<' '<<nes[b][1]<<endl;
                cout<<half[G[i][0]]<<' '<<half[G[i][1]]<<endl;
        }*/
        if (G[i].size()==2){
            if (A[i]==1){
                unite(G[i][0],G[i][1],0);
            }
            else{
                unite(G[i][0],G[i][1],1);
            }
        }
        else if (G[i].size()==1){
            ll p = G[i][0];
            ll par = F(p);
            if (A[i]==1){
                del(par);
                nes[par][half[p]^1] = 1;
                add(par);
            }
            else{
                del(par);
                nes[par][half[p]] = 1;
                add(par);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}