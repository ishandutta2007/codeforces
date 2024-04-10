#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
const int MAXN = 1e6+7;
const int N = 3e5+7;
const ll INF = 1e18;
ll val[MAXN];
pair<ll,ll> A[N];
pair<ll,ll> offers[13270034+1000];
ll ans[N];
void solve() {
    int n,C;
    cin>>n>>C;
    for(int i = 1;i<=n;++i){
        ll c,d,h;
        cin>>c>>d>>h;
        val[c] = max(val[c],d*h);
    }
    int m;
    cin>>m;
    for(int i = 1;i<=m;++i){
        ll d,c;
        cin>>d>>c;
        A[i] = {d*c,i};
    }
    vector<pair<ll,ll> > cur;
    for(int i = 1;i<MAXN;++i)
        if (val[i])
            cur.push_back({i,val[i]});
    int ptr = 0;
    for(int qnt = 1;qnt<=C;++qnt){
        while(!cur.empty() && cur.back().first*qnt>C)
            cur.pop_back();
        for(auto [cost,B]:cur)
            offers[++ptr] = {B*qnt,cost*qnt};
    }
    sort(offers+1,offers+1+ptr);
    sort(A+1,A+1+m);
    ll mi = INF;
    for(int i = m;i>=1;--i){
        while(ptr>0 && offers[ptr].first>A[i].first){
            mi = min(mi,offers[ptr].second);
            --ptr;
        }
        ans[A[i].second] = mi>C?-1:mi;
    }
    for(int i = 1;i<=m;++i)
        cout<<ans[i]<<' ';
    cout<<endl;
}
signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}