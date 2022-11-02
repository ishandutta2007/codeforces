#include <bits/stdc++.h>

using int64 = long long;

const int N = 100005;

int n, m;

char s[N];

int64 Solve1() {
    int64 Ret = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] != s[i + 1]) Ret += (int64)(m - 1) * (n - i - 1);
    }
    return Ret;
}

int64 Solve2() {
    int64 Ret = 0;
    for (int i = n - 1; i > 0; --i) {
        if (s[i] != s[i - 1]) Ret += (int64)(m - 1) * i;
    }
    return Ret;
}

int64 Solve3() {
    int64 Ret = 0, Cur = 0, last = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (i + 2 < n && s[i] != s[i + 1] && s[i] == s[i + 2]) {
            Cur = last + 1;
        } else if (i + 1 < n && s[i] != s[i + 1]) {
            Cur = 2;
        } else {
            Cur = 1;
        }
        last = Cur, Ret += Cur - 1;
    }
    return Ret;
}

int64 Solve0() { return n * (m - 1); }

int main() {
    std::cin >> n >> m >> s;
    std::cout << Solve1() + Solve2() - Solve3() + Solve0() << std::endl;
    return 0;
}