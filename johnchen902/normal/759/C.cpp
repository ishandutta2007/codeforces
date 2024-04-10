#include <cstdio>
#include <algorithm>
using namespace std;
int sum[(1 << 17) * 2 - 1];
int maxi[(1 << 17) * 2 - 1];
void add(int x, int v, int l = 0, int r = 1 << 17, int k = 0) {
    if(r - l == 1) {
        sum[k] += v;
        maxi[k] = sum[k];
    } else {
        int m = (l + r) / 2;
        if(x < m)
            add(x, v, l, m, 2 * k + 1);
        else
            add(x, v, m, r, 2 * k + 2);
        sum[k] = sum[2 * k + 1] + sum[2 * k + 2];
        maxi[k] = max(maxi[2 * k + 2], sum[2 * k + 2] + maxi[2 * k + 1]);
    }
}
int query(int v, int l = 0, int r = 1 << 17, int k = 0) {
    if(r - l == 1)
        return l;
    int m = (l + r) / 2;
    if(maxi[2 * k + 2] < v)
        return query(v - sum[2 * k + 2], l, m, 2 * k + 1);
    else
        return query(v, m, r, 2 * k + 2);
}
int query1() {
    if(maxi[0] < 1)
        return -1;
    return query(1);
}

int x[100000];
int main() {
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int p, t;
        scanf("%d %d", &p, &t);
        p--;
        if(t == 0) {
            add(p, -1);
        } else {
            int num;
            scanf("%d", &num);
            add(p, 1);
            x[p] = num;
        }
        int j = query1();
        // fprintf(stderr, "j=%d\n", j);
        printf("%d\n", j < 0 ? -1 : x[j]);
    }
}