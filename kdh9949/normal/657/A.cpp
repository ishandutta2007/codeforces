#include <cstdio>
#include <algorithm>

using namespace std;

int n, h, d, cnt = 2;

int main(){
    scanf("%d%d%d", &n, &d, &h);
    if(d > 2 * h) {puts("-1"); return 0;}
    if(n > 2 && d == 1) {puts("-1"); return 0;}
    for(int i = 1; i <= h; i++) printf("%d %d\n", i, cnt++);
    if(d - h > 0) printf("1 %d\n", cnt++);
    for(int i = 1; i < d - h; i++) printf("%d %d\n", cnt - 2, cnt++);
    for(; cnt <= n; cnt++) printf("%d %d\n", h == 1 ? 1 : 2, cnt);
}