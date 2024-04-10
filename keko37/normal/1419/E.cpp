#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int t, n, len, res;
int bio[MAXN];
vector <pi> v;
vector <int> comp[MAXN];

void gen (int pos, int curr, int mask) {
    if (pos == len) {
        comp[mask].push_back(curr);
        return;
    }
    int br = v[pos].second, pot = 1;
    for (int i = 0; i <= br; i++) {
        int nmask = (i == 0 ? mask : mask | (1 << pos));
        gen(pos + 1, curr * pot, nmask);
        pot *= v[pos].first;
    }
}

void ispis (int mask) {
    for (int i = 0; i < comp[mask].size(); i++) {
        int val = comp[mask][i];
        if (len == 2 && mask == 3 && i == (int) comp[mask].size() - 1) break;
        cout << val << " ";
    }
}

void solve () {
    v.clear();
    for (int i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        if (cnt > 0) v.push_back({i, cnt});
    }
    if (n > 1) v.push_back({n, 1});
    len = v.size();
    for (int mask = 0; mask < (1 << len); mask++) {
        bio[mask] = 0;
        comp[mask].clear();
    }
    gen(0, 1, 0);
    res = (len == 2 && v[0].second == 1 && v[1].second == 1);
    for (int i = 0; i < len; i++) {
        ispis(1 << i);
        bio[1 << i] = 1;
        if (i == len - 1) break;
        for (int mask = 0; mask < (1 << len); mask++) {
            if ((mask & (1 << i)) && bio[mask] == 0 && mask != ((1 << i) + (1 << (i + 1))) && mask != (1 << len) - 1) {
                ispis(mask);
                bio[mask] = 1;
            }
        }
        ispis((1 << i) + (1 << (i + 1)));
        bio[(1 << i) + (1 << (i + 1))] = 1;
    }
    if (bio[(1 << len) - 1] == 0) ispis((1 << len) - 1);
    if (len == 2) cout << comp[3].back();
    cout << '\n';
    cout << res << '\n';
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        solve();
    }
    return 0;
}