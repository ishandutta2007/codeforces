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
const int N = 1000111;
int f[N], d[N];

int main() {
    int n;
    cin >> n;

    vector<int> a;
    int lim = 8;
    for (int msk = 1; msk < (1 << lim); ++msk) {
        int res = 0;
        for (int i = 0; i < lim; ++i)
            if (msk & (1 << i)) res = res * 10 + 1;
            else res *= 10;
        if (res <= n)
            a.push_back(res);
    }
    sort(a.begin(), a.end());

    memset(f, 63, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int x : a) {
            if (x <= i && f[i - x] + 1 < f[i]) {
                f[i] = f[i - x] + 1;
                d[i] = x;
            }
        }

    vector<int> ans;
    while (n) {
        ans.push_back(d[n]);
        n -= d[n];
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", int(ans.size()));
    for (int x : ans) {
        printf("%d ", x);
    }
    cout << endl;

    return 0;
}