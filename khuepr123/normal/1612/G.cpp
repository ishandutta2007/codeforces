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

int ans = 0;
int way = 1;

int cnt[maxN];
int fac[maxN];

void mult(int vl){
    way *= vl; way %= mod;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(cnt, 0, sizeof(cnt));
    fac[0] = 1;
    for1(i, 1, maxN - 1) fac[i] = (fac[i - 1] * i) % mod;
    int rang = 0;
    cin >> z; while(z--){
        cin >> x; ++cnt[x]; rang += x;
    }
    for2(i, maxN - 1, 2){
        mult(fac[cnt[i]]);
        mult(fac[cnt[i]]);
        rang -= cnt[i] * 2; rang %= mod;
        cnt[i - 2] += cnt[i];
        int dis = ((rang + cnt[i]) * cnt[i]) % mod;
        ans += dis * (i - 1);
        ans %= mod;
    }
    mult(fac[cnt[1]]);
    cout << (ans % mod + mod) % mod << " ";
    cout << (way % mod + mod) % mod << " ";

}