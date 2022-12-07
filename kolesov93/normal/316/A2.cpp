#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

const int N = 100111;
char w[N];
int ans[N];
int l;
bool used[N];
bool first[N];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    gets(w);
    int n = strlen(w);

    int cnt = 0;
    bool have = false;
    int cntl = 0;
    for (int i = 0; i < n; ++i) {
        if (w[i] >= 'A' && w[i] <= 'Z') {
            if (!used[ w[i] ]) {
                ++cntl;
            }
            used[ w[i] ] = true;
            if (i == 0) {
                have = true;
                first[ w[i] ] = true;
            }
        } else if (w[i] == '?') {
            ++cnt;
        }
    }
    ans[0] = 1;
    l = 1;
    bool qm = false;
    if (w[0] == '?') {
        cnt--;
        qm = true;
    }

    if (!have) {
        int cur = 10;
        while (cntl--) {
            int all = 0;
            for (int i = 0; i < l; ++i) {
                all += ans[i] * cur;
                ans[i] = all % 10;
                all /= 10;
            }
            while (all) {
                ans[l++] = all % 10;
                all /= 10;
            }
            cur--;
        }
    } else {
        ans[0] = 9;
        cntl--;
        int cur = 9;
        while (cntl--) {
            int all = 0;
            for (int i = 0; i < l; ++i) {
                all += ans[i] * cur;
                ans[i] = all % 10;
                all /= 10;
            }
            while (all) {
                ans[l++] = all % 10;
                all /= 10;
            }
            cur--;
        }
    }

    if (qm) {
    int all = 0;
    for (int i = 0; i < l; ++i) {
        all += ans[i] * 9;
        ans[i] = all % 10;
        all /= 10;
    }
    while (all) {
        ans[l++] = all % 10;
        all /= 10;
    }
    }

    for (int i = l - 1; i >= 0; --i) {
        putchar('0' + ans[i]);
    }
    while (cnt--) {
        putchar('0');
    }
    puts("");

    return 0;
}