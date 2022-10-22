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

string s;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> z;
    vector<ii> ord;
    for1(i, 1, z) s += "0";
    for1(i, 1, z){
        cout << "? "; s[i - 1] = '1'; cout << s << endl;
        s[i - 1] = '0';
        cin >> x;
        ord.pb({x, i});
    }
    sort(all(ord));
    int sum = 0;
    for(ii cc : ord){
        s[cc.se - 1] = '1';
        cout << "? " << s << endl;
        cin >> y;
        if(y - cc.fi == sum) sum = y;
        else s[cc.se - 1] = '0';
    }
    cout << "! " << sum << endl;
}