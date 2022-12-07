#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int d1[7][2] = {2, 0, 1, 2, -1, 2, -2, 0, -1, -2, 1, -2, 2, 0};
const int d2[7][2] = {-1, 2, -2, 0, -1, -2, 1, -2, 2, 0, 1, 2, -1, 2};

long long n;

long long cal(int x) {
    return 3LL * x * (x + 1);
}

int get(long long n) {
    int l = 1, r = 1000000000;
    while (l < r) {
        int mid = (l + r)>>1;
        if (cal(mid) < n) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main() {
    scanf("%lld", &n);
    if (n == 0) {
        printf("0 0\n");
        return 0;
    }
    int m = get(n);
    long long yu = n - cal(m - 1);
    long long yuu = yu % m;
    yu /= m;
    long long x = 0, y = 0;
    x += d1[yu][0] * m;
    y += d1[yu][1] * m;
    x += d2[yu][0] * yuu;
    y += d2[yu][1] * yuu;
    printf("%lld %lld\n", x, y);
    return 0;
}