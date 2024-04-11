/*
 * @Author: your name
 * @Date: 2021-09-02 22:36:29
 * @LastEditTime: 2021-09-07 18:01:52
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

const int maxn = 100 + 10;

int n;
char str[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T-- ) {
        scanf("%d", &n);
        scanf("%s", str + 1);
        int lens = strlen(str + 1);
        std::string ans;
        for (int i = 1 ; i <= lens ; i++ ) {
            if (str[i] == 'U') {
                ans.push_back('D');
            } else if(str[i] == 'D'){
                ans.push_back('U');
            } else if (str[i] == 'L' || str[i] == 'R') {
                ans.append("LR");
                ++i;
            }
        }
        printf("%s\n", ans.c_str());
    }
    return 0;
}