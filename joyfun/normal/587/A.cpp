#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2000005;
int n, w, cnt[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &w);
        cnt[w]++;
    }
    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        cnt[i + 1] += cnt[i] / 2;
        cnt[i] %= 2;
        ans += cnt[i];
    }
    printf("%d\n", ans);
    return 0;
}