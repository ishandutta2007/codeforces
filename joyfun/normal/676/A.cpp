#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N = 105;
int n, a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            swap(a[i], a[j]);
            int s, b;
            for (int k = 0; k < n; k++) {
                if (a[k] == 1) s = k;
                if (a[k] == n) b = k;
            }
            ans = max(ans, abs(b - s));
            swap(a[i], a[j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}