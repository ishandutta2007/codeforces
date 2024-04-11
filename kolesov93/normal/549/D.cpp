#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>
#include <memory.h>
#include <string>
#include <cstring>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ld PI = acos(-1.);

const int N = 111;
ll a[N][N];
char w[N][N];

int main() {
    int n, m;
    cin >> n >> m;
    scanf("\n");
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        scanf("%s", w[i]);
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            ll need = w[i][j] == 'W' ? -1 : 1;
            ll add = need - a[i][j];
            if (add != 0) {
                ans += 1;

                for (int x = 0; x <= i; ++x)
                    for (int y = 0; y <= j; ++y)
                        a[x][y] += add;
            }
        }
    }

    cout << ans << endl;

    return 0;
}