#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define lowbit(x) (x&(-x))

const int N = 100005;

int n, q, bit[N];

void add(int x, int v) {
    while (x < N) {
        bit[x] += v;
        x += lowbit(x);
    }
}

int get(int x) {
    int ans = 0;
    while (x) {
        ans += bit[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        add(i, 1);
    int tp, a, b;
    int l = 1, r = n, flip = 0;
    while (q--) {
        scanf("%d%d", &tp, &a);
        if (tp == 1) {
            int tl = l, tr = r;
            if (a <= (r - l + 1) / 2) {
                if (flip) {
                    for (int i = a; i >= 1; i--) {
                        add(r - 2 * i + 1, get(tr - a + i) - get(tr - a + i - 1));
                        r--;
                    }
                }
                else {
                    for (int i = a; i >= 1; i--) {
                        add(l + 2 * i - 1, get(tl + a - i) - get(tl + a - i - 1));
                        l++;
                    }
                }
            } else {
                a = r - a - l + 1;
                if (!flip) {
                    for (int i = a; i >= 1; i--) {
                        add(r - 2 * i + 1, get(tr - a + i) - get(tr - a + i - 1));
                        r--;
                    }
                }
                else {
                    for (int i = a; i >= 1; i--) {
                        add(l + 2 * i - 1, get(tl + a - i) - get(tl + a - i - 1));
                        l++;
                    }
                }
                flip ^= 1;
            }
        }
        else {
            scanf("%d", &b);
            if (flip) {
                a = r - a;
                b = r - b;
                swap(a, b);
            } else {
                a += l - 1; 
                b += l - 1;
            }
            printf("%d\n", get(b) - get(a));
        }
    }
    return 0;
}