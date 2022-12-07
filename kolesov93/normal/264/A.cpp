#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

char s[1111111];
int a[1111111];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;
    gets(s);
    n = strlen(s);

    int r = n;
    int l = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'l') {
            a[r--] = (i + 1);
        } else {
            a[l++] = (i + 1);
        }
    }

    for (int i =1; i <= n; ++i) {
        printf("%d\n", a[i]);
    }

    

    return 0;
}