#include <cstdio>

int n, c, t, b, p, ans;

int main(){
    scanf("%d%d%d", &n, &b, &p);
    c = n;
    while(c > 1){
        for(t = 2; t <= c; t *= 2); t /= 2;
        ans += b * t + t / 2;
        c -= t / 2;
    }
    printf("%d %d", ans, n * p);
}