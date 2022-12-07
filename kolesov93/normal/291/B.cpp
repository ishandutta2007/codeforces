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

using namespace std;

const int N = 555555;
char w[N];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    gets(w);
    int n = strlen(w);

    int pos = 0;
    while (pos < n) {
        while (pos < n && w[pos] == ' ') pos++;
        if (pos >= n) break;

        if (w[pos] == '\"') {
            int begin = ++pos;
            while (pos < n && w[pos] != '\"') pos++;

            putchar('<');
            for (int i = begin; i < pos; ++i) putchar(w[i]);
            puts(">");
            pos++;
        } else {
            int begin = pos++;
            while (pos < n && w[pos] != ' ') pos++;

            putchar('<');
            for (int i = begin; i < pos; ++i) putchar(w[i]);
            puts(">");
        }
    }

    return 0;
}