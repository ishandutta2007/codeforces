#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pp;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
const ll DIM = 100007;
const ll INF = 10e16;
const ll MOD1 = (10e9)+7;
const ll MOD2 = 2147483647;
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define po(x) (1<<x)
struct node{
    ll fi,sc,th;
};
bool const operator<(const node &a,const node &b){
    if (a.fi==b.fi){
        if (a.sc==b.sc)return a.th<b.th;
        return a.sc<b.sc;
    }
    return a.fi<b.fi;
}
bool const operator==(const node &a,const node &b){
    return (a.fi==b.fi && a.sc==b.sc && a.th==b.th);
}
ll n,ans[DIM],cnt[DIM];
vector<node> V[DIM];
ll Ch(ll a,node &val,ll pos){
    if (val.fi==a){
        if (pos==1)swap(val.fi,val.fi);
        if (pos==2)swap(val.fi,val.sc);
        if (pos==3)swap(val.fi,val.th);
        return 1;
    }
    if (val.sc==a){
        if (pos==1)swap(val.sc,val.fi);
        if (pos==2)swap(val.sc,val.sc);
        if (pos==3)swap(val.sc,val.th);
        return 1;
    }
    if (val.th==a){
        if (pos==1)swap(val.th,val.fi);
        if (pos==2)swap(val.th,val.sc);
        if (pos==3)swap(val.th,val.th);
        return 1;
    }
    return 0;
}
int main()
{
    //cout<<'A'-33<<endl;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;

    forn(i,n-2){
        node x;
        cin>>x.fi>>x.sc>>x.th;
        cnt[x.fi]++;
        cnt[x.sc]++;
        cnt[x.th]++;

        V[x.fi].pb(x);
        V[x.sc].pb(x);
        V[x.th].pb(x);
    }
    ll start = 0;
    forn(i,n){
        if (cnt[i]==1){
            start = i;
            break;
        }
    }
    node got;
    for(node to:V[start]){
        if ((cnt[to.fi]==1 && to.fi!=start) ||(cnt[to.sc]==1 && to.sc!=start)|| (cnt[to.th]==1 && to.th!=start))continue;
            got = to;
            break;

    }
    if (got.fi==start)swap(got.fi,got.th);
    if (got.sc==start)swap(got.th,got.sc);
    if (cnt[got.sc]<cnt[got.fi])swap(got.sc,got.fi);
    node prev = {got.th,got.fi,got.sc};
    ll p = 4;
    ans[1] = got.th;
    ans[2] = got.fi;
    ans[3] = got.sc;
    ll cur = got.sc;
    node next;
    while(p<=n){
        for(node to:V[cur]){
            if (Ch(prev.sc,to,1) && Ch(prev.th,to,2) && !Ch(prev.fi,to,1)){
                got = to;
                break;
            }
        }
        ans[p++] = got.th;
        cur = got.th;
        prev = got;
    }
    forn(i,n)cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}

// 5
// 0 1 0 1 0 1010
// 1 3 9  27
// 1 7 16 70
// 1 2 1 0