/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

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

int cnt[4];
int ans = 0;
int res[4];

int C(int nn, int kk){
    if(kk == 0) return 1;
    if(kk == 1) return nn;
    if(kk == 2) return (nn * (nn - 1)) / 2;
    if(kk == 3) return (nn * (nn - 1) * (nn - 2)) / 6;
    return 0;
}

void back(int pos, int nm){
    if(pos == 4){
        // for1(i, 1, 3){
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        int fk = 0;
        if((a[1] + a[2]) != 3) fk ^= 1;
        if((a[3] + a[2]) != 3) fk ^= 1;
        if((a[1] + a[3]) != 3) fk ^= 1;
        if(fk == 0) return;
        bool what = 0;
        if(a[1] == 0 && a[2] == 0 && a[3] == 2) what = 1;
        for1(i, 0, 3) res[i] = 0;
        for1(i, 1, 3) ++res[a[i]];
        int fuk = 1;
        for1(i, 0, 3){
            fuk *= C(cnt[i], res[i]);
        }
        ans += fuk;
        return;
    }
    for1(i, nm, 3){
        a[pos] = i;
        back(pos + 1, i);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    for1(i, 1, n){
        cin >> x >> y;
        x /= 2; x %= 2;
        y /= 2; y %= 2;
        cnt[x * 2 + y]++;
    }
    back(1, 0);
    cout << ans << endl;
}