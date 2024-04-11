#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>
#include <cstring>
#include <bitset>
#include <ctime>
#include <functional>
#include <numeric>

typedef long long LL;
typedef unsigned long long uLL;

int read() {
    int s = 0,w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

LL readl() {
    LL s = 0,w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}

///////////////////////////////////// wanna become a master

int n;


int main() {
    int T = read();
    while (T-- ) {
        n = read();
        std::string str = std::to_string(n);
        std::reverse(str.begin(), str.end());
        int lens = str.size();
        int ans = 0;
        for (int s = 0 ; s < (1 << (std::max(0, lens - 2))) ; s++ ) {
            int cnt = 1;
            // bool has = true;
            for (int i = 0 ; i < lens ; i++ ) {
                int val = str[i] - '0';
                if (i - 2 >= 0 && (s & (1 << (i - 2)))) --val;
                if (s & (1 << i)) val += 10;
                int tmp = 0;
                bool ok = false;
                for (int j = 0 ; j < 10 ; j++ ) {
                    if (val - j >= 0 && val - j < 10) {
                        ++tmp;
                        // if (val - j == val) ok = true;
                    }
                }
                cnt *= tmp;
                // has = has && ok;
            }
            // printf("cnt = %d\n", cnt);
            // if (has) --cnt;
            ans += cnt;
        }
        printf("%d\n", ans - 2);
    }
    return 0;
}