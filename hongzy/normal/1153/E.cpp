#include <algorithm>
#include <cstdio>
using namespace std;

int n, x[3], y[3], c, d, ans;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        printf("? %d %d %d %d\n", i, 1, i, n);
        fflush(stdout);
        scanf("%d", &ans);
        if(ans & 1) x[++ c] = i;
    }
    for(int i = 1; i <= n; i ++) {
        printf("? %d %d %d %d\n", 1, i, n, i);
        fflush(stdout);
        scanf("%d", &ans);
        if(ans & 1) y[++ d] = i;
    }
    if(c && d) {
        bool mark = 0; int x0, y0;
        for(int i = 1; i <= 2; i ++) {
            for(int j = 1; j <= 2; j ++) {
                printf("? %d %d %d %d\n", x[i], y[j], x[i], y[j]);
                fflush(stdout);
                scanf("%d", &ans);
                if(ans == 1) {
                    if(mark) {
                        printf("! %d %d %d %d\n", x0, y0, x[i], y[j]);
                        fflush(stdout); break ;
                    } else {
                        mark = 1; x0 = x[i]; y0 = y[j];
                    }
                }
            }
        }
    } else if(c) {
        int l = 1, r = n, mid;
        while(l < r) {
            mid = (l + r) >> 1;
            printf("? %d %d %d %d\n", 1, l, x[1], mid);
            fflush(stdout);
            scanf("%d", &ans);
            if(ans & 1) r = mid;
            else l = mid + 1;
        }
        printf("! %d %d %d %d\n", x[1], l, x[2], l);
        fflush(stdout);
    } else if(d) {
        int l = 1, r = n, mid;
        while(l < r) {
            mid = (l + r) >> 1;
            printf("? %d %d %d %d\n", l, 1, mid, y[1]);
            fflush(stdout);
            scanf("%d", &ans);
            if(ans & 1) r = mid;
            else l = mid + 1;
        }
        printf("! %d %d %d %d\n", l, y[1], l, y[2]);
        fflush(stdout);
    }
    return 0;
}