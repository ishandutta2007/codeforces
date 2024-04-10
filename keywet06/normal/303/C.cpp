#include <bits/stdc++.h>

using namespace std;

const int D = 5005;
const int N = 1000005;
const int M = 13000000;

int n, K, cnt;
int a[D];
int vis[N], head[N];

std::vector<int> all;
std::vector<int> V[N];

struct edge {
    int k, nxt;
} e[M];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> K;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int v = abs(a[i] - a[j]);
            e[++cnt] = (edge){i, head[v]}, head[v] = cnt;
        }
    }
    for (int i = 1;; ++i) {
        int sz = 0;
        for (int j = 0; j <= 1000000 && sz <= K; j += i) {
            for (int $ = head[j]; $; $ = e[$].nxt) {
                int k = e[$].k;
                if (vis[k] ^ i) sz++, vis[k] = i;
                if (sz > K) break;
            }
        }
        if (sz <= K) return std::cout << i << '\n', 0;
    }
    return 0;
}