#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 200005;

int n, b[N], Max = 0, Min = INF;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    Max = max(Max, b[i]);
    Min = min(Min, b[i]);
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
    if (Max == b[i])
        cnt1++;
    if (Min == b[i])
        cnt2++;
    }
    if (Max == Min) printf("0 %lld\n", (long long)cnt1 * (cnt1 - 1) / 2);
    else printf("%d %lld\n", Max - Min, (long long)cnt1 * cnt2);
    return 0;
}