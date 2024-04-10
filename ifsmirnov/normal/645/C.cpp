#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef vector<int> vi;

const int maxn = 100500;

int n;
int a[maxn], k;
char buf[maxn];

int s[maxn];

int get(int l, int r) {
    return s[r] - (l ? s[l-1] : 0);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &k);
    ++k;
    scanf("%s", buf);
    forn(i, n) {
        if (buf[i] == '0') ++s[i];
        if (i) s[i] += s[i-1];
    }

    int best = 10000000;
    forn(i, n) if (buf[i] == '0') {
        int l = 0, r = 1000000;
        while (r-l > 1) {
            int m = (r+l) / 2;
            int lp = max(i - m, 0);
            int rp = min(i + m, n-1);
            if (get(lp, rp) >= k) {
                r = m;
            } else {
                l = m;
            }
        }
        best = min(best, r);
    }

    cout << best << endl;

    return 0;
}