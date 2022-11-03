#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

bitset<7001> b[100005];
bitset<7001> mo[7100];
bitset<7001> a[7100];
int ok[7100];
bitset<7001> ww;


int main() {
    ios_base::sync_with_stdio(false);
    int n, q;
    for(int i = 1; i <= 7000; ++i) {
        ok[i] = 1;
    }
    for (int j = 2; j <= 83; ++j) {
        int w = j * j;
        for (int p = w; p <= 7000; p += w) {
            ok[p] = 0;
        }
    }
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= 7000; ++i) {
        int zu = 1;
        for(int j = i; j <= 7000; j += i, ++zu) {
            if (ok[zu])
                mo[i].set(j, 1);
        }
    }
    for (int i = 1; i <= 7000; ++i) {
        for (int j = i; j <= 7000; j += i) {
            a[j].set(i, 1);
        }
    }
    for(int i = 0; i < q; ++i) {
        int t, x, y, z, v;
        scanf("%d", &t);
        switch(t) {
            case 1:
                scanf("%d%d", &x, &v);
                --x;
                b[x] = a[v];
                break;
            case 2:
                scanf("%d%d%d", &x, &y, &z);
                --x;
                --y;
                --z;
                b[x] = b[y] ^ b[z];
                break;
            case 3:
                scanf("%d%d%d", &x, &y, &z);
                --x;
                --y;
                --z;
                b[x] = b[y] & b[z];
                break;
            case 4:
                scanf("%d%d", &x, &v);
                --x;
                printf("%d", (b[x] & mo[v]).count() & 1);
                break;
        }
    }
    printf("\n");
}