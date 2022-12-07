#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;

bool judge(int mid) {
    int an = n - (mid / 2 - mid / 6);
    int bn = m - (mid / 3 - mid / 6);
    int s = mid / 6;
    if (an > 0) s -= an;
    if (bn > 0) s -= bn;
    return s >= 0;
}

int main() {
    scanf("%d%d", &n, &m);
    int l = 0, r = 5000000;
    while (l < r) {
        int mid = (l + r)>>1;
        if (judge(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}