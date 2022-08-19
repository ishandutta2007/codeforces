#include <bits/stdc++.h>
using namespace std;
constexpr int P = 1E9 + 7, S = 1 << 16;
using Array = array<int, S>;
void inc(int &a, int b) {(a += b) >= P ? a -= P : 0;}
void dec(int &a, int b) {(a -= b) < 0 ? a += P : 0;}
void fmtAnd(Array &arr) {
    for (int i = 1; i < S; i *= 2)
        for (int j = 0; j < S; j += 2 * i)
            for (int k = 0; k < i; ++k)
                inc(arr[j + k], arr[i + j + k]);
}
void ifmtAnd(Array &arr) {
    for (int i = 1; i < S; i *= 2)
        for (int j = 0; j < S; j += 2 * i)
            for (int k = 0; k < i; ++k)
                dec(arr[j + k], arr[i + j + k]);
}
void fmtOr(Array &arr) {
    for (int i = 1; i < S; i *= 2)
        for (int j = 0; j < S; j += 2 * i)
            for (int k = 0; k < i; ++k)
                inc(arr[i + j + k], arr[j + k]);
}
void ifmtOr(Array &arr) {
    for (int i = 1; i < S; i *= 2)
        for (int j = 0; j < S; j += 2 * i)
            for (int k = 0; k < i; ++k)
                dec(arr[i + j + k], arr[j + k]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    function<Array(int, int)> solve = [&](int l, int r) {
        if (r - l == 1) {
            Array dp {};
            for (int c = 0; c < 4; ++c) {
                if ('A' + c != s[l] && s[l] != '?')
                    continue;
                int w = 0;
                for (int j = 0; j < 16; ++j)
                    w |= (j >> c & 1) << j;
                ++dp[w];
            }
            for (int c = 0; c < 4; ++c) {
                if ('a' + c != s[l] && s[l] != '?')
                    continue;
                int w = S - 1;
                for (int j = 0; j < 16; ++j)
                    w &= ~((j >> c & 1) << j);
                ++dp[w];
            }
            return dp;
        }
        int x = l + 1, sum = 1;
        while (sum != 0) {
            if (s[x] == '(')
                ++sum;
            if (s[x] == ')')
                --sum;
            ++x;
        }
        auto left = move(solve(l + 1, x - 1)), right = move(solve(x + 2, r - 1));
        Array dp {};
        if (s[x] != '|') {
            auto a = left, b = right;
            fmtAnd(a);
            fmtAnd(b);
            for (int i = 0; i < S; ++i)
                a[i] = 1LL * a[i] * b[i] % P;
            ifmtAnd(a);
            for (int i = 0; i < S; ++i)
                inc(dp[i], a[i]);
        }
        if (s[x] != '&') {
            auto a = left, b = right;
            fmtOr(a);
            fmtOr(b);
            for (int i = 0; i < S; ++i)
                a[i] = 1LL * a[i] * b[i] % P;
            ifmtOr(a);
            for (int i = 0; i < S; ++i)
                inc(dp[i], a[i]);
        }
        return dp;
    };
    auto f = solve(0, (int)s.length());
    array<int, 16> val;
    fill(val.begin(), val.end(), -1);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int w = 0;
        for (int j = 0; j < 4; ++j) {
            int x;
            cin >> x;
            w |= x << j;
        }
        int y;
        cin >> y;
        val[w] = y;
    }
    int ans = 0;
    for (int i = 0; i < S; ++i) {
        int x = 1;
        for (int j = 0; j < 16; ++j)
            if (val[j] != -1 && (i >> j & 1) != val[j])
                x = 0;
        inc(ans, x * f[i]);
    }
    cout << ans << endl;
    return 0;
}