#include <cstdio>
#include <vector>

int tab[1000007];
std::vector<int> v[1000007];
long long ile[1000007];
long long wyn[1000007];
const int mod = 1000000007;

long long dfs(int a, int oj) {
    ile[a] = tab[a];
    for (auto it : v[a])
        if (it != oj)
            ile[a] += dfs(it, a);
    return ile[a];
}

long long gcd(long long a, long long b) {
    while (b != 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &tab[i]);
    for (int i = 2; i <= N; i++) {
        int p;
        scanf("%d", &p);
        v[i].push_back(p);
        v[p].push_back(i);
    }
    dfs(1, 1);
    long long S = ile[1];
    for (int i = 1; i <= N; i++) {
        long long pos = S / gcd(S, ile[i]);
        if (pos <= N)
            wyn[pos]++;
    }
    for (int i = N; i >= 1; i--)
        for (int w = i + i; w <= N; w += i)
            wyn[w] += wyn[i];
    for (int i = 1; i <= N; i++)
        wyn[i] = (wyn[i] == i);
//    for (int i = 1; i <= N; i++)
//        printf("%d ", wyn[i]);
    int s = 0;
    for (int i = N; i >= 1; i--) {
        if (wyn[i] == 0)
            continue;
        for (int w = i + i; w <= N; w += i) {
            wyn[i] += wyn[w];
            wyn[i] %= mod;
        }
        s += wyn[i];
        s %= mod;
    }
    printf("%lld", (s - wyn[1] + 1 + mod) % mod);
    return 0;
}