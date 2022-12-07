#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <set>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <time.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;

const int N = 1111;

ll d[N], s[N];

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int m, k;
    cin >> m >> k;

    int n = m + 1;

    for (int i = 0; i < m; ++i) {
        cin >> d[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> s[i];
    }

    int fuel = 0;
    int cool = s[0];
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        fuel += s[i];
        ans += d[i];
        if (s[i] > cool) cool = s[i];
        while (fuel < d[i]) {
            fuel += cool;
            ans += k;
        }
        fuel -= d[i];
    }

    cout << ans << endl;

    return 0;
}