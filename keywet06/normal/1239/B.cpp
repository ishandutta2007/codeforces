#include <bits/stdc++.h>

const int N = 300005;
const int M = N << 1;

int n, Mi, Mc, Ans, A = 1, B = 1;
int Sum[M];

std::string s;

void solve(int s, int e) {
    int cnt1 = 0;
    for (int i = s; i < e; ++i) {
        if (Sum[i] == Mi + 1) ++cnt1;
    }
    if (Ans < cnt1) A = s, B = e, Ans = cnt1;
    int p = s, TCnt = 0;
    for (int i = s + 1; i < e; ++i) {
        if (Sum[i] == Mi + 1) {
            if (Ans < TCnt + Mc) Ans = TCnt + Mc, A = p + 1, B = i;
            p = i, TCnt = 0;
        }
        if (Sum[i] == Mi + 2) ++TCnt;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> s;
    for (int i = 0; i < n; ++i) Sum[i + 1] = Sum[i] + (s[i] == '(' ? 1 : -1);
    if (Sum[n]) return std::cout << "0\n1 1\n", 0;
    for (int i = 1; i <= n; ++i) Mi = std::min(Mi, Sum[i]);
    for (int i = n + 1; i <= 2 * n; ++i) Sum[i] = Sum[i - n];
    for (int i = 1; i <= n; ++i) Mc += Sum[i] == Mi;
    if (Ans < Mc) Ans = Mc;
    int Flag = -1;
    for (int i = 1; i <= n * 2; ++i) {
        if (Sum[i] == Mi) {
            if (~Flag) solve(Flag + 1, i);
            Flag = i;
        }
    }
    std::cout << Ans << '\n';
    std::cout << (A > n ? A - n : A) << ' ' << (B > n ? B - n : B) << '\n';
    return 0;
}