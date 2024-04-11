/*
 * @Author: your name
 * @Date: 2021-09-02 22:36:29
 * @LastEditTime: 2021-09-07 18:15:28
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /QQMail/micromsg2/bderec/test/test.cpp
 */

#include <time.h>
#include <cstring>

#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

const int maxn = 3e5 + 10;

int sum[maxn];
int a,b;

void init() {
    for (int i = 1 ; i < maxn ; i++ ) {
        sum[i] = (sum[i - 1] ^ i);
    }
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T-- ) {
        scanf("%d%d", &a, &b);
        int ans = a;
        if (sum[a - 1] != b) {
            if ((sum[a - 1] ^ b) == a) ans += 2;
            else ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}