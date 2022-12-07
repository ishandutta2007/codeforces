#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;
int n, cnt;
long long a[N], k;

long long abss(long long x) {
    if (x < 0) return -x;
    return x;
}

bool judge() {
    if (k == 0) {
        if (a[0] == 10001) {
            if ((n + 1 - cnt) % 2 == 0) return false;
            return true;
        } else {
            if (a[0] == 0) return true;
            return false;
        }
    }
    if (cnt) return (n + 1) % 2 == 0;
    for (int i = n; i > 0; i--) {
        a[i - 1] += a[i] * k;
        if (abss(a[i - 1]) > 10000LL) return false;
    }
    return a[0] == 0;
}

int main() {
    scanf("%d%lld", &n, &k);
    char op[105];
    for (int i = 0; i <= n; i++) {
        scanf("%s", op);
        if (op[0] == '?') {
            a[i] = 10001;
            cnt++;
        }
        else sscanf(op, "%lld", &a[i]);
    }
    printf("%s\n", judge() ? "Yes" : "No");
    return 0;
}