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
const int maxN = 1000005;
const ll oo = 1e18 + 7;
int n, a[maxN];
int x, y, z, k;

bool good[maxN];
bool sad[maxN];
vector<bool> pre;
vector<bool> suf;
int pr[maxN];
int m;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
        cin >> n >> m;
        for1(i, 1, m) good[i] = 1;
        for1(i, 1, m) sad[i] = 1;
        for1(i, 1, m + 1) pre.pb(false);
        for1(i, 1, n){
            suf.clear();
            suf.pb(false);
            char c;
            for1(j, 1, m){
                cin >> c; suf.pb((c == 'X'));
            }
            for1(j, 2, m){
                if(suf[j - 1] && pre[j]) good[j] = 0;
            }
            pre = suf;
        }
    for1(i, 0, m){
        pr[i] = 0;
        good[i] = !good[i];
    }
    for1(i, 1, m){
        pr[i] = pr[i - 1];
        if(good[i]) ++pr[i];
    }
    int o; cin >> o; while(o--){
        cin >> x >> y;
        if(pr[y] - pr[x]) cout << "NO\n";
        else cout << "YES\n";
    }
}