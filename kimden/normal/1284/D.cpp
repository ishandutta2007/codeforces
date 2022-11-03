#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int mod;
inline int add(int x, int y) {
    int z = x + y;
    if (z >= mod) {
        z -= mod;
    }
    return z;
}

inline int mul(int x, int y) {
    return (x * ll(y)) % mod;
}

int n;
const int N = 100500;
const int HA = 3;
int sa[N], ea[N], sb[N], eb[N], va[N][HA], vb[N][HA];
int h[N][HA];
mt19937 mt(84512 + time(nullptr));
uniform_int_distribution<int> uid;

void get_val(int v[N][HA], int s[N], int e[N]) {
    vector<pii> ends, starts;
    for (int i = 0; i < n; ++i) {
        ends.emplace_back(e[i], i);
    }
    for (int i = 0; i < n; ++i) {
        starts.emplace_back(s[i], i);
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    vector<vector<int>> hep(HA, vector<int>(n));
    vector<vector<int>> hss(HA, vector<int>(n));
    vector<int> cep(HA, 0);
    vector<int> css(HA, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < HA; ++j) {
            cep[j] ^= h[ends[i].second][j];
            hep[j][i] = cep[j];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < HA; ++j) {
            css[j] ^= h[starts[i].second][j];
            hss[j][i] = css[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        int i1 = lower_bound(ends.begin(), ends.end(), make_pair(s[i], -998244353)) - ends.begin();
        int i2 = upper_bound(starts.begin(), starts.end(), make_pair(e[i], 998244353)) - starts.begin();
        --i1;
        for (int j = 0; j < HA; ++j) {
            v[i][j] = (i1 < 0 ? 0 : hep[j][i1]) ^ (i2 >= n ? 0 : hss[j][i2]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
//n = 100000;
    for (int i = 0; i < n; ++i) {
//        sa[i] = mt() % 1000000000 + 1;
//        sb[i] = mt() % 1000000000 + 1;
//        ea[i] = mt() % 1000000000 + 1;
//        eb[i] = mt() % 1000000000 + 1;
//        if (sa[i] > ea[i]) swap(sa[i], ea[i]);
//        if (sb[i] > eb[i]) swap(sb[i], eb[i]);
        cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
        for (int j = 0; j < HA; ++j) {
            h[i][j] = uid(mt);
        }
    }
    get_val(va, sa, ea);
    get_val(vb, sb, eb);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < HA; ++j) {
            if (va[i][j] != vb[i][j]) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
}