#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[100001], b[100001];
int pre[100001], suf[100001];
int main() {
    scanf("%s %s", a, b);
    int n = strlen(a), m = strlen(b);
    pre[0] = 0;
    for(int i = 1; i <= m; i++) {
        pre[i] = pre[i - 1];
        while(pre[i] < n && a[pre[i]] != b[i - 1])
            pre[i]++;
        pre[i]++;
    }
    suf[m] = n;
    for(int i = m - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] - 1;
        while(suf[i] >= 0 && a[suf[i]] != b[i])
            suf[i]--;
    }
    int left = 0, right = m;
    for(int i = 0; i <= m; i++) {
#if 0
        for(int j = i; j <= m; j++) {
            if(pre[i] <= suf[j]) {
                if(right - left > j - i)
                    left = i, right = j;
            }
        }
#endif
        auto it = lower_bound(suf + i, suf + m + 1, pre[i]);
        int j = it - suf;
        if(j <= m) {
            if(right - left > j - i)
                left = i, right = j;
        }
    }

    if(left == 0 && right == m) {
        puts("-");
    } else {
        for(int i = 0; i < left; i++)
            putchar(b[i]);
        for(int i = right; i < m; i++)
            putchar(b[i]);
        putchar('\n');
    }
}