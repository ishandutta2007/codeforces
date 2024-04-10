#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;

typedef long long ll;

int n;
ll A, d[N], b[N];

int main() {
    scanf("%d%lld", &n, &A);
    ll sum = 0;
    for (int i = 0; i < n; i++)
        scanf("%lld", &d[i]), sum += d[i];
    for (int i = 0; i < n; i++) {
        ll l = max(1LL, A - sum + d[i]);
        ll r = min(d[i], A - n + 1);
        b[i] = d[i] - r + l - 1;
    }
    for (int i = 0; i < n; i++)
        printf("%lld%c", b[i], i == n - 1 ? '\n' : ' ');
    return 0;
}