#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;

int n;
int a[N], b[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int aa = 0, bb = 0;
        for (int j = i; j < n; j++) {
            aa |= a[j];
            bb |= b[j];
            ans = max(ans, aa + bb);
        }
    }
    printf("%d\n", ans);
    return 0;
}