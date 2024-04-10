#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int INF = 0x3f3f3f3f;
int n;
map<int, int> cnt;
int a;

int mi[35];

int main() {
    mi[0] = 1;
    for (int i = 1; i <= 31; i++) mi[i] = mi[i - 1] * 2;
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        for (int j = 0; j <= 30; j++) {
            int b = mi[j] - a;
            ans += cnt[b];
        }
        cnt[a]++;
    }
    printf("%lld\n", ans);
    return 0;
}