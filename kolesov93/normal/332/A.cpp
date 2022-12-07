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
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acosl(-1.);
using namespace std;

char w[2222];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;
    scanf("%d\n", &n);
    gets(w);

    int l = strlen(w);
    int ans = 0;
    for (int i = 0; i < l; ++i) {
        if (i > 2 && i % n == 0) {
            if (w[i - 1] == w[i - 2] && w[i - 1] == w[i - 3]) {
                ++ans;
                w[i] = w[i - 1];
            }
        }
    }
    cout << ans << endl;

    return 0;
}