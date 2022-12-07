#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200005;
const int INF = 0x3f3f3f3f;

struct Seg {
    int l, r;
    Seg() {}
    Seg(int l, int r) {
        this->l = l;
        this->r = r;
    }
} seg[N];

int n, x, w;

bool cmp(Seg a, Seg b) {
    return a.r < b.r;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &w);
        seg[i] = Seg(x - w, x + w);
    }
    sort(seg, seg + n, cmp);
    int ans = 0;
    int r = -INF;
    for (int i = 0; i < n; i++) {
        if (seg[i].l >= r) {
            r = seg[i].r;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}