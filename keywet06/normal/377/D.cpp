#include <bits/stdc++.h>

using namespace std;

struct segtree {
    static const int DEPTH = 19;
    static const int N = 1 << DEPTH;
    int mxv[2 * N], ofs[2 * N], rg[2 * N];
    void init() {
        for (int i = 0; i < 2 * N; ++i) mxv[i] = ofs[i] = 0;
        for (int i = N; i < 2 * N; ++i) rg[i] = i - N;
        for (int i = N - 1; i > 0; --i) adjust(i);
    }
    void adjust(int p) {
        if (p >= N)
            mxv[p] = ofs[p];
        else {
            if (mxv[p * 2] < mxv[p * 2 + 1])
                rg[p] = rg[p * 2 + 1];
            else
                rg[p] = rg[p * 2];
            mxv[p] = ofs[p] + max(mxv[p * 2], mxv[p * 2 + 1]);
        }
    }
    void add(int p, int L, int R, int depth, int val) {
        if (R <= (p << depth) || ((p + 1) << depth) <= L) return;
        if (L <= (p << depth) && ((p + 1) << depth) <= R) {
            ofs[p] += val;
            adjust(p);
            return;
        }
        add(p * 2, L, R, depth - 1, val);
        add(p * 2 + 1, L, R, depth - 1, val);
        adjust(p);
    }
    void add(int L, int R, int val) { add(1, L + N, R + N, DEPTH, val); }
    int query() { return mxv[1]; }
    int right() { return rg[1]; }
};

int N;
int L[100000], V[100000], R[100000];

vector<pair<int, pair<int, int> > > act;
segtree seg;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) scanf("%d%d%d", L + i, V + i, R + i);
    for (int i = 0; i < N; ++i) {
        act.push_back(make_pair(L[i], make_pair(0, i)));
        act.push_back(make_pair(V[i], make_pair(1, i)));
    }
    sort(act.begin(), act.end());
    seg.init();
    pair<int, pair<int, int> > ret = make_pair(-1, make_pair(0, 0));
    for (int i = 0; i < act.size(); ++i) {
        int p = act[i].second.second;
        if (act[i].second.first == 0) {
            seg.add(V[p], 300001, 1);
            seg.add(R[p] + 1, 300001, -1);
            ret =
                max(ret, make_pair(seg.query(), make_pair(L[p], seg.right())));
        } else {
            seg.add(V[p], 300001, -1);
            seg.add(R[p] + 1, 300001, 1);
        }
    }
    printf("%d\n", ret.first);
    int lf = ret.second.first, rg = ret.second.second;
    vector<int> ans;
    for (int i = 0; i < N; ++i)
        if (L[i] <= lf && rg <= R[i] && lf <= V[i] && V[i] <= rg)
            ans.push_back(i + 1);
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d%c", ans[i], (i == ans.size() - 1) ? '\n' : ' ');
    }
    return 0;
}