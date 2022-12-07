#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int cnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int get(int x) {
    if (x == 0) return cnt[0];
    int ans = 0;
    while (x) {
        ans += cnt[x % 10];
        x /= 10;
    }
    return ans;
}

int main() {
    int a, b;
    int ans = 0;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++) {
        ans += get(i);
    }
    printf("%d\n", ans);
    return 0;
}