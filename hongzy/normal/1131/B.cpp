#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int n, a, b, la = 0, lb = 0, ans = 1;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%d%d", &a, &b);
        if(a == la && b == lb) continue ;
        ans += max(0, min(a, b) - max(la, lb) + (la != lb));
        la = a; lb = b;
    }
    printf("%d\n", ans);
    return 0;
}