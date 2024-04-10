/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;;

#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const int mod = 1e9 + 7;
const int maxN = 300005;
const int blk = 548;
int n, a[maxN];
int x, y, z, k;

int cnt[maxN];
struct query{
    int l, r, ind, k;
    bool operator < (const query& oth) const{
        if(l / blk != oth.l / blk) return l < oth.l;
        if((l / blk) % 2 == 0) return r > oth.r;
        return r < oth.r;
    }
}qr[maxN];
int ans[maxN];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> n >> o;
    for1(i, 1, n){
        cin >> a[i];
    }
    int l = 1, r = 0;
    memset(cnt, 0, sizeof(cnt));
    for1(i, 1, o){
        cin >> qr[i].l >> qr[i].r >> qr[i].k;
        qr[i].ind = i;
    }
    sort(qr + 1, qr + o + 1);
    for1(i, 1, o){
        int le = qr[i].l;
        int ri = qr[i].r;
        while(r < ri) ++cnt[a[++r]];
        while(l > le) ++cnt[a[--l]];
        while(r > ri) --cnt[a[r--]];
        while(l < le) --cnt[a[l++]];
        k = qr[i].k;
        int res = mod;
        int len = (r - l + 1);
        int lim = (len / k);
        // cout << l << " " << r << " " << len << " " << lim << endl;
        // for1(i, 1, n) cout << cnt[i] << " ";
        // cout << endl;
        for1(wtfffff, 1, 75){
            int ind = (rng() % len) + l;
            if(cnt[a[ind]] > lim) res = min(res, a[ind]);
        }
        if(res == mod) res = -1;
        ans[qr[i].ind] = res;
    }
    for1(i, 1, o) cout << ans[i] << endl;
}