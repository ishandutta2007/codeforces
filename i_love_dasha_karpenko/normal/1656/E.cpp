#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
const int N = 1e5+7;
vector<int> G[N];
pair<ll,ll> ans[N];
const pair<ll,ll> operator + (pair<ll,ll> a,pair<ll,ll> b){
    return {a.first+b.first,a.second+b.second};
}
const pair<ll,ll> operator - (pair<ll,ll> a,pair<ll,ll> b){
    return {a.first-b.first,a.second-b.second};
}
const pair<ll,ll> operator * (pair<ll,ll> a,ll b){
    return {a.first*b,a.second*b};
}
void dfs(int v,int par,pair<ll,ll> sum_top = {0,0},pair<ll,ll> need ={0,0} ){
    if (v==par){
        ans[v] = {1,0};
        pair<ll,ll> to_val = {0,1};
        for(int to:G[v]){
            dfs(to,v,ans[v]+(to_val*(int(G[v].size())-1)),to_val);
        }
        return;
    }
    else{
        pair<ll,ll> to_val =  sum_top;
        ans[v] = need-(to_val*int(G[v].size()-1));
        for(int to:G[v]){
            if (to==par)
                continue;
            dfs(to,v,sum_top+ans[v]+(to_val*(int(G[v].size())-2)),to_val);
        }
    }

}
void solve() {
    ll n;
    cin>>n;
    for(int i = 1;i<=n;++i)
        G[i].clear();
    for(int i = 1;i<n;++i){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1);
    set<int> S;
    for(int i = -n;i<=n;++i) S.insert(i);
    S.erase(0);
    const int LIM = 1e5;
    for(int i = 1;i<=n;++i) {
        if (ans[i].first != 0 && ans[i].second % ans[i].first == 0) {
            S.erase(-ans[i].second / ans[i].first);
        }
        if (ans[i].first<0){
            int l = (LIM-ans[i].second)/ans[i].first,r = (-LIM-ans[i].second)/ans[i].first;
            while(!S.empty() && *S.begin()<l)
                S.erase(S.begin());
            while(!S.empty() && *S.rbegin()>r)
                S.erase(*S.rbegin());
        }
        if (ans[i].first>0){
            int l = (-LIM-ans[i].second)/ans[i].first,r = (LIM-ans[i].second)/ans[i].first;
            while(!S.empty() && *S.begin()<l)
                S.erase(S.begin());
            while(!S.empty() && *S.rbegin()>r)
                S.erase(*S.rbegin());
        }

    }
    assert(!S.empty());
    int v = *S.begin();
    
    for(int i = 1;i<=n;++i) {
        int val =  ans[i].first * v + ans[i].second;
        //assert(-int(1e5)<=val && val<=int(1e5));
        cout<<val<<' ';
    }
    cout<<endl;
}
signed main(){

    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin>>t;
    while(t--)
        solve();
}