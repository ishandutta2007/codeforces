#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 1'000'000'007;
constexpr int N = 1111;

char _s[N];
ll solve() {
    int x;
    scanf("%d%s", &x, _s);
    ll ls = strlen(_s);
    vector<char> s(_s, _s + ls);
    for (int i = 1; i <= x; i++) {
        int v = s[i - 1] - '1';
        if (s.size() < x) {
            vector<char> sub(s.begin() + i, s.end());
            for (int it = 0; it < v; it++) s.insert(s.end(), sub.begin(), sub.end());
        }
        ls = (ls + (ls - i) * v) % mod;
    }
    return ls;
}


int main() {
    int z;
    for (scanf("%d", &z); z--; printf("%lld\n", (solve() % mod + mod) % mod));
}