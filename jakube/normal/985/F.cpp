#include <bits/stdc++.h>
using namespace std;

using PA = pair<array<int, 26>, int>;
vector<long long> powers;
const int MOD = 1e9 + 7;

PA combine(PA a, PA b) {
    PA ret;
    ret.second = a.second + b.second;
    for (int i = 0; i < 26; i++) {
        ret.first[i] = (a.first[i] * powers[b.second] + b.first[i]) % MOD;
    }
    return ret;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    powers.resize(n + 1);
    powers[0] = 1;
    for (int i = 1; i <= n; i++) {
        powers[i] = powers[i-1] * 2 % MOD;
    }
    vector<array<int, 26>> psum(n + 1);
    for (int i = 0; i < 26; i++)
        psum[0][i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            psum[i+1][j] = (psum[i][j] + powers[i] * (s[i] == 'a' + j)) % MOD;
        }
    }

    auto get = [&psum](auto idx, int len) {
        auto res = psum[idx + len];
        for (int i = 0; i < 26; i++) {
            res[i] -= psum[idx][i];
            if (res[i] < 0)
                res[i] += MOD;
        }
        return res;
    };
    
    for (int i = 0; i < m; i++) {
        int x, y, len;
        cin >> x >> y >> len;
        x--;
        y--;
        if (x > y)
            swap(x, y);
        auto X = get(x, len);
        auto Y = get(y, len);
        for (int i = 0; i < 26; i++) {
            X[i] = X[i] * powers[y - x] % MOD;
        }
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        if (X == Y)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}