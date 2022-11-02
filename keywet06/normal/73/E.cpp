#include <memory.h>

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <map>
#include <set>
#include <vector>
using namespace std;

const int N_ = 1300000;
const int N = N_ + 5;

bool u[N];

int n, x;
int a[N];

int solve() {
    if (x == 2) return 0;
    if (a[0] == 1) return 1;
    for (int i = 2; i * i <= N_; ++i) {
        if (!u[i]) {
            for (int j = i * i; j <= N_; j += i) u[j] = 1;
        }
    }
    int res = 0, ka = 0, lim = min(N_, x);
    if (lim & 1) --lim;
    for (int i = 2; i <= lim; ++i) {
        if (!u[i]) {
            while (ka < n && a[ka] < i) ++ka;
            if (ka == n || a[ka] != i) return -1;
            ++ka, ++res;
        }
    }
    return res;
}

int main() {
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    printf("%d\n", solve());
    return 0;
}