/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")*/
// only when really needed

/* GNU G++17 7.3.0: No long long for faster code
   GNU G++17 9.2.0 (64 bit, msys 2): Long long only for faster code */
 
#include <bits/stdc++.h>
  
#define for1(i,a,b) for (int i = a; i <= b; i++)
#define for2(i,a,b) for (int i = a; i >= b; i--)
#define int long long

#define sz(a) (int)a.size()
#define pii pair<int,int>
 
/*
__builtin_popcountll(x) : Number of 1-bit
__builtin_ctzll(x) : Number of trailing 0
*/
 
#define PI 3.1415926535897932384626433832795
#define INF 1000000000000000000
#define MOD 1000000007
#define MOD2 1000000009
#define EPS 1e-6

using namespace std;

int n, q, a[524300], prime[305], inv[65], cnt;
int prodtree[1048600], primetree[1048600], lazy[1048600][2];

int power(int x, int n) {

    int res = 1;
    while (n > 0) {
        if (n & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }

    return res;

}

int inverse(int x) {
    return power(x, MOD - 2);
}

void build(int id, int l, int r) {

    lazy[id][0] = 1;

    if (l == r) {
        prodtree[id] = a[l];
        primetree[id] = prime[a[l]];
        return;
    }

    int m = (l + r)/2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);

    prodtree[id] = prodtree[id * 2] * prodtree[id * 2 + 1] % MOD;
    primetree[id] = primetree[id * 2] | primetree[id * 2 + 1];

}

void push1(int id, int l, int r) {

    int t = lazy[id][0];
    if (t > 1) {

        int m = (l + r)/2;
        int br = power(t, m - l + 1);

        prodtree[id * 2] = prodtree[id * 2] * br % MOD;
        prodtree[id * 2 + 1] = prodtree[id * 2 + 1] * br % MOD;

        lazy[id * 2][0] = lazy[id * 2][0] * t % MOD;
        lazy[id * 2 + 1][0] = lazy[id * 2 + 1][0] * t % MOD;

        lazy[id][0] = 1;
    }

}

void push2(int id) {

    int t = lazy[id][1];
    primetree[id * 2] |= t;
    primetree[id * 2 + 1] |= t;

    lazy[id * 2][1] |= t;
    lazy[id * 2 + 1][1] |= t;

    lazy[id][1] = 0;
 
}

void update(int id, int l, int r, int tl, int tr, int val) {

    if (l > tr || r < tl) return;
    if (l >= tl && r <= tr) {
        int br = power(val, r - l + 1);
        prodtree[id] = prodtree[id] * br % MOD;
        lazy[id][0] = lazy[id][0] * val % MOD;

        primetree[id] |= prime[val];
        lazy[id][1] |= prime[val];
        return;
    }

    push1(id, l, r);
    push2(id);

    int m = (l + r)/2;
    update(id * 2, l, m, tl, tr, val);
    update(id * 2 + 1, m + 1, r, tl, tr, val);

    prodtree[id] = prodtree[id * 2] * prodtree[id * 2 + 1] % MOD;
    primetree[id] = primetree[id * 2] | primetree[id * 2 + 1];

}

int get_prod(int id, int l, int r, int tl, int tr) {

    if (l > tr || r < tl) return 1;
    if (l >= tl && r <= tr) return prodtree[id];

    push1(id, l, r);
    int m = (l + r)/2;
    return get_prod(id * 2, l, m, tl, tr) * get_prod(id * 2 + 1, m + 1, r, tl, tr) % MOD;

}

int get_prime(int id, int l, int r, int tl, int tr) {

    if (l > tr || r < tl) return 0;
    if (l >= tl && r <= tr) return primetree[id];

    push2(id);
    int m = (l + r)/2;
    return get_prime(id * 2, l, m, tl, tr) | get_prime(id * 2 + 1, m + 1, r, tl, tr);

}

signed main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // freopen("input.inp", "r", stdin);
    // freopen("output.out", "w", stdout);

    for1(i,2,300) if (!prime[i]) {
        for1(j,1,300/i) prime[i * j] += (1ll << cnt);
        inv[cnt++] = (i - 1) * inverse(i) % MOD;
    }

    cin >> n >> q;
    for1(i,1,n) cin >> a[i];
    build(1, 1, 1 << 19);

    while (q--) {

        string s;
        int l, r;
        cin >> s >> l >> r;

        if (s[0] == 'M') {
            int val;
            cin >> val;
            update(1, 1, 1 << 19, l, r, val);
        }
        else {
            int ans = get_prod(1, 1, 1 << 19, l, r);
            int pr = get_prime(1, 1, 1 << 19, l, r);

            for1(i,0,61) if (pr & (1ll << i)) ans = ans * inv[i] % MOD;
            cout << ans << "\n";
        }

    }
    
}