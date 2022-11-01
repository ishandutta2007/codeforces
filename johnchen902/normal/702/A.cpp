#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n, last;
    scanf("%d %d", &n, &last);
    int ans = 1, cur = 1;
    for(int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x);
        if(x > last) {
            ans = max(ans, ++cur);
        } else {
            cur = 1;
        }
        last = x;
    }
    printf("%d\n", ans);
}