#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, a[N], cnt[N];

const int INF = 0x3f3f3f3f;
int vis[N];

int main() {
    scanf("%d", &n);
    int Max = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        Max = max(Max, a[i]);
        int tmp = a[i];
        while (tmp) {
            if (tmp&1) cnt[tmp]++;
            tmp /= 2;
        }
    }
    int ans = INF;
    for (int i = 1; i < N; i += 2) {
        if (cnt[i] == n) {
            long long tmp = i;
            long long sb = Max;
            while (tmp <= sb) {
                vis[tmp] = i;
                int tot = 0;
                int to = (int)tmp;
                for (int j = 0; j < n; j++) {
                    int cao = a[j];
                    while (cao > tmp || vis[cao] == 0) {
                        cao /= 2;
                        tot++;
                    }
                    while (cao != tmp) {
                        cao *= 2;
                        tot++;
                    }
                }
                ans = min(ans, tot);
                tmp *= 2;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}