#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int P = 998244353;
const int64 P2 = 1ll * P * P;

template <class T>
void sort(vector<T> &a) {
    sort(a.begin(), a.end());
}

template <class T, class Cmp>
void sort(vector<T> &a, Cmp cmp) {
    sort(a.begin(), a.end(), cmp);
}

vector<vector<int>> operator+(const vector<vector<int>> &a,
                              const vector<vector<int>> &b) {
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x = a[i][j] + b[i][j];
            x >= P ? x -= P : 0;
            c[i][j] = x;
        }
    }
    return c;
}

vector<vector<int>> operator*(const vector<vector<int>> &a,
                              const vector<vector<int>> &b) {
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int64 x = 0;
            for (int k = 0; k < n; ++k) {
                x += 1ll * a[i][k] * b[k][j];
                x >= P2 ? x -= P2 : 0;
            }
            c[i][j] = x % P;
        }
    }
    return c;
}

vector<int> operator*(const vector<vector<int>> &a, const vector<int> &b) {
    int n = a.size();
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        int64 x = 0;
        for (int j = 0; j < n; ++j) {
            x += 1ll * a[i][j] * b[j];
            x >= P2 ? x -= P2 : 0;
        }
        c[i] = x % P;
    }
    return c;
}

void Main(int test_id = 1) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int m;
    scanf("%d", &m);
    vector<vector<pair<int, int>>> cell(n);
    for (int i = 0; i < m; ++i) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        cell[x - 1].emplace_back(y - 1, c - 1);
    }
    for (int i = 0; i < n; ++i) {
        sort(cell[i]);
    }
    vector<vector<int>> able(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &able[i][j]);
        }
    }
    vector<vector<vector<int>>> Tra(3);
    vector<vector<vector<int>>> Sum(32);
    for (int Col = 0; Col < 3; ++Col) {
        vector<vector<int>> a(64, vector<int>(64));
        vector<int> SG(3);
        for (int Sta = 0; Sta < 64; ++Sta) {
            SG[0] = Sta & 3;
            SG[1] = (Sta >> 2) & 3;
            SG[2] = Sta >> 4;
            vector<int> cnt(4);
            for (int i = 0; i < 3; ++i) {
                if (able[Col][i]) ++cnt[SG[i]];
            }
            int NSG;
            for (int i = 0; i < 4; ++i) {
                if (cnt[i] == 0) {
                    NSG = i;
                    break;
                }
            }
            int Nst = ((Sta << 2) | NSG) & 63;
            a[Nst][Sta] = 1;
        }
        Tra[Col] = a;
    }
    Sum[0] = Tra[0] + Tra[1] + Tra[2];
    for (int i = 1; i < 32; ++i) Sum[i] = Sum[i - 1] * Sum[i - 1];
    vector<int> Dp(4);
    Dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        vector<int> g(64);
        g[63] = 1;
        int Cur = 0;
        for (auto [x, Col] : cell[i]) {
            int Del = x - Cur;
            int Per = 0;
            while (Del) {
                if (Del & 1) {
                    g = Sum[Per] * g;
                }
                Del >>= 1;
                ++Per;
            }
            g = Tra[Col] * g;
            Cur = x + 1;
        }
        int Del = a[i] - Cur;
        int Per = 0;
        while (Del) {
            if (Del & 1) g = Sum[Per] * g;
            Del >>= 1, ++Per;
        }
        vector<int> Way(4);
        for (int i = 0; i < 64; ++i) {
            int x = Way[i & 3] + g[i];
            x >= P ? x -= P : 0;
            Way[i & 3] = x;
        }
        vector<int> Ndp(4);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                Ndp[i ^ j] = (Ndp[i ^ j] + 1ll * Dp[i] * Way[j]) % P;
            }
        }
        Dp = Ndp;
    }
    printf("%d\n", Dp[0]);
}

int main() {
    Main();
    return 0;
}