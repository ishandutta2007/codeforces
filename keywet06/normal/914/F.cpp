#include <bits/stdc++.h>

const int B = 2;
const int C = 26;
const int N = 100005;

char v[B];
char s[N], now[N];

int n, q, x, y, o;

std::bitset<N> a;
std::bitset<N> se[C];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> s + 1, n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) se[s[i] - 'a'].set(i, 1);
    std::cin >> q;
    for (int i = 1; i <= q; ++i) {
        std::cin >> o;
        if (o == 1) {
            std::cin >> x >> v;
            se[s[x] - 'a'].set(x, 0), se[v[0] - 'a'].set(x, 1);
            s[x] = v[0];
        } else {
            std::cin >> x >> y >> now + 1;
            a.set();
            int l = strlen(now + 1);
            for (int i = 1; i <= l; ++i) a &= (se[now[i] - 'a'] >> (i - 1));
            int la = (a >> x).count(), lb = (a >> (y - l + 2)).count();
            std::cout << ((la - lb < 0) ? 0 : la - lb) << '\n';
        }
    }
    return 0;
}