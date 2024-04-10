#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
using namespace std;

const int N = 5000005;
int a[N];
int n, k;
int vis[N * 2], cnt;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int l = 1;
    int Max = 0;
    int ansl, ansr;
    for (int r = 1; r <= n; r++) {
        if (vis[a[r]] == 0) cnt++;
        vis[a[r]]++;
        while (l <= r && cnt > k) {
            if (vis[a[l]] == 1) cnt--;
            vis[a[l]]--;
            l++;
        }
        if (Max < r - l + 1) {
            Max = r - l + 1;
            ansl = l;
            ansr = r;
        }
    }
    printf("%d %d\n", ansl, ansr);
    return 0;
}