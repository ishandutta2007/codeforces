#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 1000000;

vector <pair <int, int>> vec;
vector <int> graf[MAXN+5];
int par[MAXN+5];
int sz[MAXN+5];

int root(int x){
    if(par[x] == x) return x;
    return par[x] = root(par[x]);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        vec.push_back({x, i});
    }
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        par[i] = i;
    }
    ll res = 0;
    sort(vec.begin(), vec.end());
    for(auto cvor : vec){
        int v = cvor.second;
        ll val = cvor.first;
        sz[v] = 1;
        vector <ll> vals;
        for(auto c : graf[v]){
            if(!sz[c]) continue;
            vals.push_back(sz[root(c)]);
        }
        ll tr = 1;
        for(auto c : vals){
            res += val*c*tr;
            tr += c;
        }
        for(auto c : graf[v]){
            if(!sz[c]) continue;
            int a1 = root(v);
            int b1 = root(c);
            if(sz[a1] < sz[b1]) swap(a1, b1);
            sz[a1] += sz[b1];
            par[b1] = a1;
        }
    }
    reverse(vec.begin(), vec.end());
    for(int i=1; i<=n; i++){
        sz[i] = 0;
        par[i] = i;
    }
    for(auto cvor : vec){
        int v = cvor.second;
        ll val = cvor.first;
        sz[v] = 1;
        vector <ll> vals;
        for(auto c : graf[v]){
            if(!sz[c]) continue;
            vals.push_back(sz[root(c)]);
        }
        ll tr = 1;
        for(auto c : vals){
            res -= val*c*tr;
            tr += c;
        }
        for(auto c : graf[v]){
            if(!sz[c]) continue;
            int a1 = root(v);
            int b1 = root(c);
            if(sz[a1] < sz[b1]) swap(a1, b1);
            sz[a1] += sz[b1];
            par[b1] = a1;
        }
    }
    cout << res << "\n";
    return 0;
}