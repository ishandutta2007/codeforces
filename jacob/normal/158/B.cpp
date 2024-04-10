#include <algorithm>
#include <cstdio>
#include <vector>
#include <climits>
using namespace std;

int main(void) {
    int n, m;
    scanf("%d", &n);        
    int cnt[5];
    fill_n(cnt, 5, 0);
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        cnt[t]+=1;
    }
    int res = 0;
    res += cnt[4];
    cnt[4] = 0;
    res += cnt[3];
    cnt[1] -= min(cnt[1], cnt[3]);
    res += cnt[2] / 2;
    cnt[2] %= 2;
    if (cnt[2]) {
        ++res;
        cnt[2] -= 1;
        cnt[1] -= min(cnt[1], 2);
    }
    res += (cnt[1] + 3) / 4;
    printf("%d\n", res);
    return 0;
}