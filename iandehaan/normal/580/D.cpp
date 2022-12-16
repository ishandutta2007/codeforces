#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
// cost, (pos, mask)
using nxt = pair<ll, pair<ll, ll>>;
using vi = vector<ll>;
#define pb push_back
#define mp make_pair

ll memo[18][(1 << 18)];
ll dist[18][18];
ll a[18];
ll m, n, k;

ll dp(ll pos, ll mask) {
    //cout << pos << ' ' << mask << endl;
    if (mask == 0) return 0;
    if (memo[pos][mask] != -1) return memo[pos][mask];

    if (__builtin_popcount(mask) == 1) {
        return memo[pos][mask] = a[pos];
    }

    ll blah = (1 << pos) ^(-1);
    ll newmask = mask & blah;
    ll out = 0;
    for (int i = 0; i < n; i++) {
        if (i == pos) continue;
        if (mask & (1 << i)) {
            out = max(out, dist[i][pos] + dp(i, newmask));
        }
    }
    return memo[pos][mask] = out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    
    for (int i = 0; i < n; i++) cin >> a[i];

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) dist[i][j] = a[j];
    }
    
    for (int i = 0; i < k; i++) {
        ll x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        dist[x][y] += c;
    }

    // cost, (pos, mask)
    for (int i = 0; i < n; i++) {
        for (ll j = 0; j < (1 << n); j++) {
            memo[i][j] = -1;
        }
    }
    

    ll out= 0;
    for (ll mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) == m) {
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    out = max(out, dp(i, mask));
                }
            }
        }
    }
    cout << out << endl;

}