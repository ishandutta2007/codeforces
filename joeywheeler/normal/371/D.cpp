#include <cstdio>
#include <algorithm>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

#define FO(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int n;
int a[200005];
int c[200005];
int p[200005];

int gp(int i) {
    if (i == p[i]) return i;
    else return p[i] = gp(p[i]);
}

void of(int i) {
    p[i] = gp(i+1);
}

void add(int i, int x) {
    if (i == n || x == 0) return;
    else if (p[i] != i) add(gp(i), x);
    else {
        int v = min(x, a[i]-c[i]);
        x -= v;
        c[i] += v;
        if (c[i] == a[i])
            of(i);
        add(gp(i), x);
    }
}

int main() {
    scanf("%d", &n);
    FO(i,0,n)
        scanf("%d", &a[i]);
    FO(i,0,n+1)
        p[i] = i;

    int m;
    scanf("%d", &m);
    FO(i,0,m) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int ind, x;
            scanf("%d %d", &ind, &x);
            add(ind-1, x);
        } else {
            int ind;
            scanf("%d", &ind);
            printf("%d\n", c[ind-1]);
        }
    }

    return 0;
}