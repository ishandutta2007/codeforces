#include <bits/stdc++.h>

using namespace std;

template <typename T>
vector<T> vec(size_t a) {
    return vector<T>(a);
}

template <typename T, typename... Ts>
auto vec(size_t a, Ts... ts) {
    return vector<decltype(vec<T>(ts...))>(a, vec<T>(ts...));
}

int main() {
    string S;
    cin >> S;
    vector<int> zan(6);
    for (auto &p : S) ++zan[p - 'a'];
    int M;
    cin >> M;
    int N = (int)S.size();
    vector<int> allow(N, (1 << 6) - 1);
    for (int i = 0; i < M; ++i) {
        int idx;
        string s;
        cin >> idx >> s;
        allow[--idx] = 0;
        for (auto &p : s) allow[idx] |= 1 << (p - 'a');
    }
    auto mask = vec<int>(N + 1, 1 << 6);
    for (int i = N - 1; i >= 0; --i) {
        for (int j = 0; j < (1 << 6); ++j) mask[i][j] += mask[i + 1][j];
        ++mask[i][allow[i]];
    }
    for (int i = N - 1; i >= 0; --i) {
        for (int j = 0; j < 6; ++j) {
            for (int k = 0; k < (1 << 6); ++k) {
                if (k & (1 << j)) mask[i][k] += mask[i][k ^ (1 << j)];
            }
        }
    }
    auto dp = vec<int>(1 << 6);
    for (int i = 0; i < (1 << 6); ++i) {
        for (int j = 0; j < 6; ++j) {
            if ((i >> j) & 1) dp[i] += zan[j];
        }
    }
    string T;
    for (int i = 0; i < N; ++i) {
        bool ok = false;
        for (int j = 0; j < 6; ++j) {
            if ((~allow[i] >> j) & 1) continue;
            bool f1 = true;
            for (int k = 0; k < (1 << 6); ++k) {
                f1 &= dp[k] - ((k >> j) & 1) >= mask[i + 1][k];
            }
            if (f1) {
                ok = true, T += (char)(j + 'a');
                for (int k = 0; k < (1 << 6); ++k) dp[k] -= (k >> j) & 1;
                break;
            }
        }
        if (!ok) return cout << "Impossible" << endl, 0;
    }
    cout << T << endl;
    return 0;
}