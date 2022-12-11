#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;

int c[N], d[N], t[N], h[N], n;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", c + i), t[i] = c[i] - c[i - 1];
    for(int i = 1; i <= n; i ++) scanf("%d", d + i), h[i] = d[i] - d[i - 1];
    if(c[1] != d[1]) return puts("No"), 0;
    sort(t + 1, t + n + 1); sort(h + 1, h + n + 1);
    for(int i = 1; i <= n; i ++) {
        if(t[i] != h[i]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
/*
a[i] = c[i] - c[i - 1]
c[i - 1] c[i] c[i + 1]
c[i] - c[i - 1], c[i + 1] - c[i]
c[i - 1] c[i + 1] + c[i - 1] - c[i] c[i + 1]
c[i + 1] - c[i], c[i] - c[i - 1]
(x, y) -> (y, -x) -> (-x, -y) -> (-y, x)
(x, -y) -> (-y, -x) -> (y, x) ->
*/