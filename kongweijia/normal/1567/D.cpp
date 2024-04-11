/*
 * @Author: your name
 * @Date: 2021-09-02 22:36:29
 * @LastEditTime: 2021-09-07 22:09:02
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

int s, n;

int main() {
    int T;
    scanf("%d", &T);
    while (T-- ) {
        scanf("%d%d", &s, &n);
        for (int i = 1 ; i < n ; i++ ) {
            int num = 1;
            while ((s / num) >= 10) num *= 10;
            s -= num;
            while (s < n - i) {
                s += num / 10 * 9;
                num /= 10;
            }
            printf("%d ", num);
        }
        printf("%d\n", s);
    }
    return 0;
}