#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int w[1002] = {}, b[1002] = {};

int par[1002] = {};
int siz[1002] = {};

void make_set(int v){
    par[v] = v;
    siz[v] = 1;
}

int get_set(int v){
    if(par[v] != v){
        return par[v] = get_set(par[v]);
    }
    return v;
}

void union_sets(int v, int u){
    v = get_set(v);
    u = get_set(u);
    if(v == u){
        return;
    }
    if(siz[v] < siz[u]){
        swap(v, u);
    }
    par[u] = v;
    siz[v] += siz[u];
}

int ans[2002][1001] = {};

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m, WW;
    cin >> n >> m >> WW;
    int x, y;
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        make_set(i);
    }
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        x--;
        y--;
        union_sets(x, y);
    }

    map<int, vector<int>> mp;
    map<int, pii> mp1; /// parent / (weight / beauty)
    for(int i = 0; i < n; i++){
        int q = get_set(i);
        mp[q].push_back(i);
        mp1[q].first += w[i];
        mp1[q].second += b[i];
    }
    for(int j = 0; j <= WW; j++){
        ans[0][j] = 0;
    }
    for(auto pr: mp){
        for(int j = 1; j <= WW; j++){
            ans[1][j] = ans[0][j];
        }
        for(int p: pr.second){
            for(int j = 1; j <= WW; j++){
                if(w[p] <= j){
                    ans[1][j] = max(ans[0][j - w[p]] + b[p], ans[1][j]);
                  //  cerr << "YEAH updated by " << p << " in cmoponent " << pr.first << endl;
                }
            }
        }
        for(int j = 1; j <= WW; j++){
            if(mp1[pr.first].first <= j){
                ans[1][j] = max(ans[0][j - mp1[pr.first].first] + mp1[pr.first].second, ans[1][j]);
            }
        }
        for(int j = 1; j <= WW; j++){
            ans[0][j] = ans[1][j];
        }
    }
    cout << ans[1][WW] << endl;
    return 0;
}