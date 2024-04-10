#include <cstdio>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

int w[200000];

static int solve1(int n) {
    if (n % 2 == 1)
        return n * (n - 1) / 2 + 1;
    return n * (n - 1) / 2 + n / 2;
}

int solve(int n) {
    for (int i = 2; ; i++)
        if (solve1(i) > n)
            return i - 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%*d %d", w + i);
    int k = min(solve(n), m);
    nth_element(w, w + k, w + m, greater<int>());
    printf("%lld\n", accumulate(w, w + k, 0LL));
}