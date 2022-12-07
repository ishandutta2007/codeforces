#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, a[N], b[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
    }
    sort(a, a + n);
    int l = 0, r = n - 1;
    while (l <= n - 1 && a[l] == b[l]) {
    l++;
    }
    while (r >= 0 && a[r] == b[r]) {
    r--;
    }
    if (l >= r) {
    printf("yes\n");
    printf("1 1\n");
    }
    else {
    int flag = 1;
    int aa = l, bb = r;
    for (int i = l; i <= r; i++) {
        if (a[i] != b[r - i + l]) {
        flag = 0;
        break;
        }
    }
    if (flag) {
        printf("yes\n");
        printf("%d %d\n", aa + 1, bb + 1);
    }
    else printf("no\n");
    }
    return 0;
}