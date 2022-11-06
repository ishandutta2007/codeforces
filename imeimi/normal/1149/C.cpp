#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long llong;
typedef pair<int, int> pii;

int n, q;
char in[200000];
int sum[200000];

const int inf = 1e9;
struct node {
    int L, M, R, LM, MR, LMR, lz;
    void init(int x) {
        L = R = x;
        M = -(x + x);
        LM = MR = -x;
        LMR = 0;
        lz = 0;
    }
    node operator+(const node &p) const {
        node ret;
        ret.lz = 0;
        ret.L = max(L, p.L);
        ret.M = max(M, p.M);
        ret.R = max(R, p.R);
        ret.LM = max(LM, p.LM);
        ret.LM = max(ret.LM, L + p.M);
        ret.MR = max(MR, p.MR);
        ret.MR = max(ret.MR, M + p.R);
        ret.LMR = max(LMR, p.LMR);
        ret.LMR = max(ret.LMR, LM + p.R);
        ret.LMR = max(ret.LMR, L + p.MR);
        return ret;
    }
    void add(int v) {
        lz += v;
        L += v;
        M -= v + v;
        R += v;
        LM -= v;
        MR -= v;
    }
} seg[1 << 19];

void init(int i, int s, int e) {
    if (s == e) {
        seg[i].init(sum[s]);
        return;
    }
    int m = (s + e) / 2;
    init(i << 1, s, m);
    init(i << 1 | 1, m + 1, e);
    seg[i] = seg[i << 1] + seg[i << 1 | 1];
}

void update(int i, int s, int e, int x, int y, int v) {
    if (e < x || y < s) return;
    if (x <= s && e <= y) {
        seg[i].add(v);
        return;
    }
    int m = (s + e) / 2;
    int lz = seg[i].lz;
    seg[i << 1].add(lz);
    seg[i << 1 | 1].add(lz);
    update(i << 1, s, m, x, y, v);
    update(i << 1 | 1, m + 1, e, x, y, v);
    seg[i] = seg[i << 1] + seg[i << 1 | 1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q >> in;
    for (int i = 0; i < n + n - 2; ++i) {
        sum[i + 1] = sum[i] + (in[i] == '(' ? 1 : -1);
    }
    init(1, 0, n + n - 2);
    printf("%d\n", seg[1].LMR);
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (in[a - 1] != in[b - 1]) {
            if (in[a - 1] == '(') {
                update(1, 0, n + n - 2, a, b - 1, -2);
            }
            else {
                update(1, 0, n + n - 2, a, b - 1, 2);
            }
            swap(in[a - 1], in[b - 1]);
        }
        printf("%d\n", seg[1].LMR);
    }
    return 0;
}