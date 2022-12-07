#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 500005;

int n, S[N];

struct SB {
    int l, r;
    int lc, rc;
    SB() {}
    SB(int l, int r, int lc, int rc) {
        this->l = l;
        this->r = r;
        this->lc = lc;
        this->rc = rc;
    }
} s[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &S[i]);
    int sn = 0;
   // s[sn++] = SB(1, 1, S[1], S[1]);
    int pre = 1;
    for (int i = 2; i <= n; i++) {
        if (S[i] != S[i - 1]) {
            continue;
        } else {
            s[sn++] = SB(pre, i - 1, S[pre], S[i - 1]);
            pre = i;
        }
    }
    s[sn++] = SB(pre, n, S[pre], S[n]);
    //s[sn++] = SB(n, n, S[n], S[n]);
    int ans = 0;
    for (int i = 0; i < sn; i++) {
        ans = max(ans, (s[i].r - s[i].l) / 2);
    }
    printf("%d\n", ans);
    for (int i = 0; i < sn; i++) {
        if (s[i].lc == s[i].rc) {
            for (int j = s[i].l; j <= s[i].r; j++)
                printf("%d ", s[i].lc);
        } else {
            int mid = (s[i].l + s[i].r) / 2;
            for (int j = s[i].l; j <= mid; j++)
                printf("%d ", s[i].lc);
            for (int j = mid + 1; j <= s[i].r; j++)
                printf("%d ", s[i].rc);
        }
    }
    printf("\n");
    return 0;
}