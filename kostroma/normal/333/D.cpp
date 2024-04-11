#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
using namespace std;
#define FILENAME "1dembedding"
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
void solve();
int main() {
#ifdef Kostroma
    freopen("in.txt", "r", stdin);
#else
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
    //ios_base::sync_with_stdio(0);
    /*freopen("in.txt", "w", stdout);
    cout << 100 << ' ' << 1000 << endl;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 1000; ++j)
            cout << rand() % 10 << ' ';
        cout << endl;
    }
    return 0;*/
    //cin >> t;
    while (t--)
        solve();
    return 0;
}

//#define int li
int n, m;
int a[1010][1010];
int mx[2][1010][1010];

int timer = 0;
int have[1010][1010];

bool exists (int c) {
    ++timer;
    for (int i = 0; i < n; ++i) {
        vector <int> now;
        for (int j = 0; j < m; ++j)
            if (a[i][j] >= c)
                now.push_back(j);
        for (int j = 0; j < now.size(); ++j)
            for (int k = j + 1; k < now.size(); ++k) {
                if (have[now[j]][now[k]] == timer)
                    return true;
                have[now[j]][now[k]] = timer;
            }
    }
    return false;
}

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    int l = 0, r = 1000000001;
    while (l + 1 < r) {
        int mm = (l + r) / 2;
        if (exists(mm))
            l = mm;
        else
            r = mm;
    }
    printf("%d", l);
}