#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 55;

int n;

ll f[N], k;

int main() {
    f[0] = 1; f[1] = 1; f[2] = 2;
    for (int i = 3; i < N; i++) f[i] = f[i - 1] + f[i - 2];
    scanf("%d%lld", &n, &k);
    int u = 1;
    while (u <= n) {
        if (f[n - u] < k) {
            printf("%d %d ", u + 1, u);
            k -= f[n - u];
            u += 2;
        } else {
            printf("%d ", u);
            u++;
        }
    }
    return 0;
}