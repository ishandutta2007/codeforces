#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, m[N], ans[N];

int main() {
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
        sum += m[i];
    }
    for (int i = 0; i < n; i++) ans[i] = sum / n;
    for (int i = 0; i < sum % n; i++) ans[i]++;
    sort(m, m + n);
    reverse(m, m + n);
    long long out = 0;
    for (int i = 0; i < n; i++) {
        if (m[i] < ans[i]) out += ans[i] - m[i];
    }
    printf("%lld\n", out);
    return 0;
}