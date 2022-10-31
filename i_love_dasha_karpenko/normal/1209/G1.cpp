#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef int ll;
typedef double ld;
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
const ll DIM = 2*10E4+7;
const ll INF = 10E17;
const ll maskszm = po(12);
const ll MAXN = 2*10E4;
ll n,q,l[MAXN+7],r[MAXN+7],cnt[MAXN+7],res = 0;
ll P[MAXN+7];
bool mc(ll a,ll b){
    return l[a]<l[b];
}
ll F(ll x){
    if (x==P[x])return x;
    return P[x] = F(P[x]);
}
void unite(ll x,ll y){
    x = F(x);
    y = F(y);
    if (x==y)return;
    if (rand()%2)swap(x,y);
    res+=min(cnt[x],cnt[y]);
    cnt[y]=max(cnt[y],cnt[x]);
    P[x] = y;

}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    memset(l,-1,sizeof(l));
    forn(i,MAXN)P[i] = i;
    forn(i,n){
        ll x;
        cin>>x;
        if (l[x]==-1)
        l[x] = i;
        r[x] = i;
        cnt[x]++;
    }
    vector<ll> V;
    forn(i,MAXN){
        if (l[i]!=-1)V.pb(i);
    }
    sort(V.begin(),V.end(),mc);
    ll last = -1;
    for(ll i = 0;i<V.size();i++){
        while (i<V.size() && last!=-1 && l[V[i]]<=r[last]){
            unite(V[i],last);
            if (r[last]<r[V[i]])last = V[i];
            i++;
        }
        if (i>=V.size())continue;
        last = V[i];
    }
    cout<<res<<endl;
    return 0;
}