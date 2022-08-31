#include <bits/stdc++.h>
using namespace std;

#define N 511111
#define INF (1<<30)
struct tree {
    int i, j;
    int v, a;
    tree *l, *r;
    tree(int i, int j): i(i), j(j), a(0) {
        if (j - i == 1) {
            l = r = NULL;
            v = i - N;
        } else {
            int k = i + j >> 1;
            l = new tree(i, k);
            r = new tree(k, j);
            v = min(l->v, r->v);
        }
    }
    void visit() {
        if (a) {
            v += a;
            if (l) {
                l->a += a;
                r->a += a;
            }
            a = 0;
        }
    }
    void dec(int I) {
        if (I <= i) {
            a--;
            visit();
        } else {
            visit();
            if (!(j <= I)) {
                l->dec(I);
                r->dec(I);
                v = min(l->v, r->v);
            }
        }
    }

    int mn(int I) {
        visit();
        if (I <= i) {
            return v;
        } else if (j <= I) {
            return +INF;
        } else {
            return min(l->mn(I), r->mn(I));
        }
    }
};
tree *bilang;
int kt;
void init() {
    bilang = new tree(0, N<<1);
}

void push(int v) {
    kt++;
    bilang->dec(v + N);
}
int get(int v) {
    return min(v, bilang->mn(v + N)) + kt;
}

int vals[N];
int main() {
    init();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vals[i]);
    }
    priority_queue<int> lows;
    int low = 0;
    for (int i = 0; i < n; i++) {
        lows.push(vals[i]);
        while (true) {
            while (!lows.empty() && lows.top() >= low) {
                push(lows.top());
                lows.pop();
            }
            if (lows.size() <= -low) break;
            low--;
        }
        printf("%d\n", get(low));
    }
}