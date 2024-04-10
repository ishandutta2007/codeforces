/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
#define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const int mod = 1e9 + 7;
const int maxN = 300005;
int n, a[maxN];
int x, y, z, k;

int buc[3][26];

vector<int> wait[3];
vector<int> pepe[3];
vector<ii> ans;

int took(vector<int> &cac){
    int g = cac.back(); cac.pop_back(); return g;
}

signed main(){
    // freopen(".inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int maxlim = mod;
    for1(i, 0, 2){
        string s; cin >> s; for(char c : s){
            ++buc[i][c - 'A'];
        }
        maxlim = min(maxlim, (int)s.size());
    }
    for1(cho, 0, 25){
        // cout << cho << endl;
        while(maxlim){
            vector<ii> por;
            for1(i, 0, 2) por.pb({buc[i][cho], i});
            sort(all(por), greater<ii>());
            if(!por[1].fi) break;
            --maxlim;
            for1(id, 0, 1) --buc[por[id].se][cho];
            wait[por[2].se].pb(cho);
        }
    }
    for1(i, 0, 2) for1(cho, 0, 25) for1(dumb, 1, buc[i][cho]){
        pepe[i].pb(cho);
    }
    for1(i, 0, 2) while(!wait[i].empty()){
        int v1 = took(wait[i]);
        int v2 = took(pepe[i]);
        ans.pb({v1, v2});
    }
    while(1){
        // find minimum size
        ii pr = {mod, mod};
        for1(i, 0, 2) pr = min(pr, {pepe[i].size(), i});
        int id1 = (pr.se + 1) % 3;
        int id2 = (id1   + 1) % 3;
        if(pepe[id1].empty()) swap(id1, id2);
        if(pepe[id1].empty()) break;
        if(pepe[id2].empty()) pepe[id2].pb(pepe[id1][0]);
        int v1 = took(pepe[id1]);
        int v2 = took(pepe[id2]);
        ans.pb({v1, v2});
    }
    cout << ans.size() << endl;
    for(ii pr : ans){
        cout << (char)(pr.fi + 'A');
        cout << (char)(pr.se + 'A') << endl;
    }
}