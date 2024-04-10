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
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

void prt(int num){
    cout << num << endl;
    exit(0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string s; cin >> s;
    s += '?';
    int cn = 1;
    vector<int> vl;
    vector<int> tot;
    for1(i, 0, s.size() - 2){
        if(s[i] != s[i + 1]){
            vl.pb(s[i] - 'A');
            tot.pb(cn);
            cn = 1;
        }
        else ++cn;
    }
    vector<int> vl2 = vl;
    reverse(all(vl2));
    for1(i, 0, vl.size() - 1){
        if(vl[i] != vl2[i]) prt(0);
    }
    for1(i, 0, vl.size() - 1){
        if(i == vl.size() / 2){
            if(tot[i] < 2) prt(0);
            prt(tot[i] + 1);
        }
        else if(tot[i] + tot[vl.size() - 1 - i] < 3) prt(0);
    }
}