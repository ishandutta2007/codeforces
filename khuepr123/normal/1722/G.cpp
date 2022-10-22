/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define all(flg) flg.begin(), flg.end()
#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define vi vector<int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define ld long double
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

void solve(vector<int> sus, int lvl){
    int sz = sus.size();
    if(sus.size() <= 10){
        for1(i, 0, sz - 2){
            a[sus[i]] |= (1 << lvl);
            a[sus[i + 1]] |= (1 << lvl);
            ++lvl;
        }
        return;
    }
    int hf = sz / 2;
    if(hf % 2) --hf;
    vector<int> s1;
    while(hf--){
        s1.pb(sus.back()); sus.pop_back();
    }
    for(int cc : s1) a[cc] |= (1 << lvl);
    solve(s1, lvl + 1);
    solve(sus, lvl + 1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o; while(o--){
        cin >> n;
        vector<int> sus;
        for1(i, 1, n) sus.pb(i);
        for1(i, 1, n) a[i] = 0;
        solve(sus, 0);
        for1(i, 1, n) cout << a[i] << " ";
        cout << endl;
        int v = 0;
        for1(i, 1, n) v ^= a[i];
    }
}