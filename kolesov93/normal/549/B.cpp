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

int n;
int a[N][N];
int cur[N], deg[N], taken[N];

int getit() {
    char c = getchar();
    while (c != '0' && c != '1') c = getchar();
    return c - '0';
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) a[i][j] = getit();
    for (int i = 0; i < n; ++i) cin >> deg[i];

    vector<int> ans;
    while (true) {
        int who = -1;
        for (int i = 0; i < n; ++i)
            if (deg[i] == cur[i] && !taken[i]) {
                who = i;
                break;
            }
        if (who == -1) break;

        ans.push_back(who + 1);
        for (int i = 0; i < n; ++i) cur[i] += a[who][i];
        taken[who] = 1;
    }

    for (int i = 0; i < n; ++i)
        if (cur[i] == deg[i]) {
            puts("-1");
            return 0;
        }

    sort(begin(ans), end(ans));
    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}