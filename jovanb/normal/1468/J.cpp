#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+45;
 
struct grana{
    int u,v;
    ll c;
};
 
bool cmp(grana x,grana y){
    return x.c < y.c;
}
 
ll n,m,k;
vector <pair<int,ll>> g[N];
vector <grana> grane;
int par[N],rnk[N];
 
int findpar(int x){
    return (par[x] == x ? x : par[x] = findpar(par[x]));
}
 
bool sameset(int x,int y){
    return findpar(x) == findpar(y);
}
 
void unite(int x,int y){
    int a = findpar(x),b = findpar(y);
    if(a == b) return;
    if(rnk[a] > rnk[b]){
        par[b] = a;
    }
    else{
        par[a] = b;
        if(rnk[a] == rnk[b]){
            rnk[b]++;
        }
    }
}
 
void solve(){
    cin >> n >> m >> k;
 
    for(int i = 1; i <= n; i++){
        g[i].clear();
    }
 
    grane.clear();
    for(int i = 1; i <= m; i++){
        int x,y,s;
        cin >> x >> y >> s;
        grane.push_back({x,y,s});
        g[x].push_back({y,s});
        g[y].push_back({x,s});
    }
 
    sort(grane.begin(),grane.end(),cmp);
    for(int i = 1; i <= n; i++){
        par[i] = i;
        rnk[i] = 0;
    }
    vector <grana> minst;
    bool veci = 0;
    ll summ = 0;
    for(auto f : grane){
        int x = f.u,y = f.v,cost = f.c;
        if(sameset(x,y)) continue;
        unite(x,y);
        minst.push_back(f);
        if(cost >= k){
            veci = 1;
            summ += cost-k;
        }
    }
    if(veci){
        cout << summ << "\n";
        return;
    }
    ll dif = 1000000000;
    for(auto f : grane){
        dif = min(dif, abs(k-f.c));
    }
    cout << dif << "\n";
    return;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}