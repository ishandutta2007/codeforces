// Hydro submission #62596c76cc64917dc46694a1@1650027638888
#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 0; char c = 0;
    while (!isdigit(c)) f |= c == '-', c = getchar();
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
    return f ? -x : x;
}

#define N 100010
#define INF (1000000010)
#define fi first
#define se second

int n, b[N];
pair<int, int> a[N];

bool check(int x) {
    for (int i = 1; i <= n; i ++) {
        if (a[i].fi > x) return false;
        else x += a[i].se;
    }
    return true;
}
bool check1(int x, int n) {
    for (int i = 1; i <= n; i ++) {
        if (b[i] >= x) return false;
        else x ++;
    }
    return true;
}

int main() {
    for (int T = read(); T --;) {
        n = read();
        for (int i = 1; i <= n; i ++) {
            a[i].se = read(), a[i].fi = 0;
            for (int j = 1; j <= a[i].se; j ++) {
                b[j] = read();
            }
            int l = 0, r = INF;
            while (l + 1 < r) {
                int mid = l + r >> 1;
                check1(mid, a[i].se) ? r = mid : l = mid;
            }
            if (check1(l, a[i].se)) r = l;
            // cout << r << " np\n";
            a[i].fi = r;
        }
        sort(a + 1, a + n + 1);
        int l = 0, r = INF;
        while (l + 1 < r) {
            int mid = l + r >> 1;
            check(mid) ? r = mid : l = mid;
        }
        if (check(l)) r = l;
        printf("%d\n", r);
    }
    return 0;
}