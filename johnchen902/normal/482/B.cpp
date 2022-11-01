#include <cstdio>
using namespace std;

constexpr int size = 128 * 1024;
int seg[size * 2 - 1];

void modify(int x, int l, int r, int nl = 0, int nr = size, int k = 0) {
    if(l <= nl && nr <= r) {
        seg[k] |= x;
    } else if(!(r <= nl || nr <= l)) {
        modify(x, l, r, nl, (nl + nr) / 2, 2 * k + 1);
        modify(x, l, r, (nl + nr) / 2, nr, 2 * k + 2);
    }
}

void magic(int nl = 0, int nr = size, int k = 0) {
    if(nr - nl >= 2) {
        seg[2 * k + 1] |= seg[k];
        seg[2 * k + 2] |= seg[k];
        magic(nl, (nl + nr) / 2, 2 * k + 1);
        magic((nl + nr) / 2, nr, 2 * k + 2);
        seg[k] = seg[2 * k + 1] & seg[2 * k + 2];
    }
}

int query(int l, int r, int nl = 0, int nr = size, int k = 0) {
    if(l <= nl && nr <= r) {
        return seg[k];
    } else if(!(r <= nl || nr <= l)) {
        return query(l, r, nl, (nl + nr) / 2, 2 * k + 1) &
               query(l, r, (nl + nr) / 2, nr, 2 * k + 2);
    } else {
        return ~0;
    }
}

int l[size], r[size], q[size];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", l + i, r + i, q + i);
        l[i]--;
        modify(q[i], l[i], r[i]);
//        for(int x : seg) fprintf(stderr, "%d ", x); puts("");
    }
    magic();
//    for(int x : seg) fprintf(stderr, "%d ", x); puts("");
    for(int i = 0; i < m; i++) {
        if(query(l[i], r[i]) != q[i]) {
            puts("NO");
//            fprintf(stderr, "%d != %d\n", query(l[i], r[i]), q[i]);
            return 0;
        }
    }
    puts("YES");
    for(int i = 0; i < n; i++)
        printf("%d ", seg[size - 1 + i]);
}