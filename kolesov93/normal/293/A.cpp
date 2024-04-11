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
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ld PI = acosl(-1.);

const int N = 2111111;
char w[N], s[N];

int a[2][2];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;
    cin >> n; cin.ignore();
    gets(w);
    gets(s);

    for (int i = 0; i < n + n; ++i) {
        int x = w[i] - '0';
        int y = s[i] - '0';
        a[x][y]++;
    }

    n += n;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            if (a[1][1]) {
                --a[1][1];
                cnt1++;
            } else if (a[1][0]) {
                --a[1][0];
                cnt1++;
            } else if (a[0][1]) {
                --a[0][1];
            } else {
                --a[0][0];
            }
        } else {
            if (a[1][1]) {
                --a[1][1];
                cnt2++;
            } else if (a[0][1]) {
                --a[0][1];
                cnt2++;
            } else if (a[1][0]) {
                --a[1][0];
            } else {
                --a[0][0];
            } 
        }
    }

    if (cnt1 > cnt2) {
        puts("First");
    } else if (cnt1 < cnt2) {
        puts("Second");
    } else {
        puts("Draw");
    }

    return 0;
}