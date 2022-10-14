#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 44;
void die() {
    cout << "REJECTED\n";
    exit(0);
}
int n, k;
ll op[N], res[N][N];
//around (1 + n/k)^n
void dfs(int i, ll dk, ll fix) {
    if(i == k) {
        if(dk&(dk-1)) die();
        if(fix && (fix + (1ll<<__builtin_ctzll(fix))) != (1ll<<n)) die();
        fix |= dk;
        if(fix && (fix + (1ll<<__builtin_ctzll(fix))) != (1ll<<n)) die();
        return;
    }
    int L = __builtin_popcountll(fix&op[i]);
    int R = __builtin_popcountll((fix|dk)&op[i]);
    ll ndk = dk & ~op[i];
    ll nfix = fix & ~op[i];
    for(; L <= R; L++) {
        dfs(i+1, ndk, nfix|res[i][L]);
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int t, x, i = 0; i < k; i++) {
        cin >> t;
        ll msk = 0;
        while(t--) {
            cin >> x;x--;
            msk |= 1ll<<x;
        }
        op[i] = msk;
        for(; msk; msk -= msk&-msk)
            res[i][__builtin_popcountll(msk)] = msk;
    }
    dfs(0, (1ll<<n)-1, 0);
    cout << "ACCEPTED\n";
}