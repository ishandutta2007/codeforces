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

string s, t;

int good, bad;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> s >> t;
        good = 0, bad = 0;
        int best = oo;
        int cac = (int)('1') + (int)('0');
        for1(i, 0, n - 1){
            if(s[i] > t[i]) ++good;
            if(s[i] < t[i]) ++bad;
        }
        if(good == bad) best = good + bad;
        for1(i, 0, n - 1){
            x = cac - s[i];
            s[i] = x;
        }
        bool killed = 1;
        for1(i, 0, n - 1){
            if(s[i] == '0' && t[i] == '1'){
                killed = 0; s[i] = '1'; break;
            }
        }
        if(!killed){
            good = 0, bad = 0;
            for1(i, 0, n - 1){
                if(s[i] > t[i]) ++good;
                if(s[i] < t[i]) ++bad;
            }
            if(good == bad) best = min(best, good + bad + 1);
        }
        if(best == oo) cout << "-1\n";
        else cout << best << endl;
    }
}