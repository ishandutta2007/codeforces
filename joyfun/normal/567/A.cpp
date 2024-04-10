#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int N = 100005;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f;

int n;
ll x[N];

ll magic(ll x) {
    if (x < 0) return -x;
    return x;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &x[i]);
    sort(x + 1, x + n + 1);
    x[0] = -INF;
    x[n + 1] = INF;
    for (int i = 1; i <= n; i++) {
        printf("%lld %lld\n", min(magic(x[i] - x[i - 1]), magic(x[i] - x[i + 1])), max(magic(x[i] - x[1]), magic(x[i] - x[n])));
    }
    return 0;
}