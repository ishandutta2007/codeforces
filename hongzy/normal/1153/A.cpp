#include <algorithm>
#include <cstdio>
using namespace std;

int n, t, s, d;
int mina, ans;

int main() {
    scanf("%d%d", &n, &t);
    mina = 1e9; ans = 1;
    for(int i = 1; i <= n; i ++) {
        scanf("%d%d", &s, &d);
        int now = s;
        while(now < t) now += d;
        if(now < mina) {
            mina = now;
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}