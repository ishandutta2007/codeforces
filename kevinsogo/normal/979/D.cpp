#include <bits/stdc++.h>
using namespace std;
const int B = 19;

struct Seg {
    int i, j;
    int c = 0;
    Seg *l, *r;
    Seg(vector<int>& a, int I, int J): i(a[I]), j(a[J]) {
        if (I == J) {
            l = r = NULL;
        } else {
            int K = I + J >> 1;
            l = new Seg(a, I, K);
            r = new Seg(a, K + 1, J);
        }
    }
    void add(int v) {
        if (i <= v && v <= j) {
            c++;
            if (l) {
                l->add(v);
                r->add(v);
                assert(c == l->c + r->c);
            }
        }
    }
    int count(int I, int J) {
        if (I <= i && j <= J) {
            return c;
        } else if (J < i || j < I) {
            return 0;
        } else {
            return l->count(I, J) + r->count(I, J);
        }
    }
};

int main() {
    int n = 100011, q;
    scanf("%d", &q);
    vector<Seg*> segs(n);
    vector<vector<int>> vals(n);
    vector<vector<int>> divs(n);
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j += i) {
            vals[i].push_back(j);
            divs[j].push_back(i);
        }
        segs[i] = new Seg(vals[i], 0, vals[i].size() - 1);
    }
    vector<bool> added(n);
    while (q--) {
        int typ;
        scanf("%d", &typ);
        if (typ == 1) {
            int u;
            scanf("%d", &u);
            if (!added[u]) {
                added[u] = true;
                for (int d : divs[u]) {
                    segs[d]->add(u);
                }
            }
        } else { // if (typ == 2) {
            int x, k, s;
            scanf("%d%d%d", &x, &k, &s);
            int ans = -1;
            if (!(x % k) && segs[k]->count(0, s -= x)) {
                ans = 0;
                for (int b = B; b--;) {
                    int desire = ((x >> b) ^ 1) & 1;
                    int ansi = ans | (desire << b);
                    int ansj = ansi | ((1 << b) - 1);
                    if (!segs[k]->count(ansi, min(ansj, s))) {
                        desire ^= 1;
                        // ansi = ans | (desire << b);
                        // ansj = ansi | ((1 << b) - 1);
                        // assert(segs[k]->count(ansi, min(ansj, s)));
                    }
                    ans |= desire << b;
                }
            }
            printf("%d\n", ans);
        }
    }
}