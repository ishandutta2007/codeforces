#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2000005;

int n, k;

struct Seg {
    int v, f;
    Seg() {}
    Seg(int v, int f) {
        this->v = v;
        this->f = f;
    }
    bool operator < (const Seg& c) const {
        if (v == c.v) return f > c.f;
        return v < c.v;
    }
} seg[N];

vector<pair<int, int> > ans;

int main() {
    scanf("%d%d", &n, &k);
    int l, r;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l, &r);
        seg[i * 2] = Seg(l, 1);
        seg[i * 2 + 1] = Seg(r, -1);
    }
    n *= 2;
    sort(seg, seg + n);
    int cnt = 0;
    int pre;
    for (int i = 0; i < n; i++) {
        if (seg[i].f == 1 && cnt == k - 1) pre = seg[i].v;
        cnt += seg[i].f;
        if (seg[i].f == -1 && cnt == k - 1) ans.push_back(make_pair(pre, seg[i].v));
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}