#include <bits/stdc++.h>

using namespace std;
#define fi first
#define sc second
#define forn(i,n) for(ll i = 1;i<=n;i++)
#define pb push_back
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pp;
const ll DIM = 100007+7;
const ll INF = 10E10;
pp cnt[DIM];
struct node{
    ll fi,sc,w;
};
vector<node> V;
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m; cin>>n>>m;
    forn(i,n)cnt[i].sc = i;
    forn(i,m){
        ll x,y,w; cin>>x>>y>>w;
        cnt[x].fi+=w;
        cnt[y].fi-=w;
    }
    sort(cnt+1,cnt+1+n);
    ll p1 = 1,p2 = n;
    while(p1<p2){
        ll mi = min(-cnt[p1].fi,cnt[p2].fi);
        cnt[p1].fi+=mi;
        cnt[p2].fi-=mi;
        if (mi!=0)
        V.pb({cnt[p2].sc,cnt[p1].sc,mi});
        if (cnt[p1].fi==0)p1++;
        if (cnt[p2].fi==0)p2--;
    }
    cout<<V.size()<<endl;
    for(node to:V)cout<<to.fi<<' '<<to.sc<<' '<<to.w<<endl;
    return 0;
}