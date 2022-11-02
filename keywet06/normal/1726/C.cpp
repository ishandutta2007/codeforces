#include <bits/stdc++.h>

const int N = 100005;

int T, n, Ans, c;
int Num[N];

std::string s;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> T;
    while (T--) {
        std::cin >> n, Ans = n;
        std::cin >> s, Num[0] = 0;
        for (auto ch : s) {
            if (ch == '(') {
                if (Num[c++]++) --Ans;
            } else {
                Num[c--] = 0;
            }
        }
        std::cout << Ans << '\n';
    }
    return 0;
}