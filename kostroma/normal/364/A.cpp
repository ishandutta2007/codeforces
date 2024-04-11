#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
void solve();
//void precalc();
int main() {
#ifdef room111
    clock_t start = clock();
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    int t = 1;
    //cout.sync_with_stdio(0);
    //precalc();
    //cin >> t;
    while (t--)
        solve();

#ifdef room111
    cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

#define int li

int a;
string s;
int sum[5000][5000];

const int C = 1000500;
int cnt[C];

void solve() {
    cin >> a >> s;
    for (int i = 0; i < s.length(); ++i) {
        int cur = 0;
        for (int j = i; j < s.length(); ++j) {
            cur += s[j] - '0';
            ++cnt[cur];
        }
    }
    int res = 0;
    if (a == 0) {
        for (int i = 1; i < C; ++i)
            res += cnt[i];
        res *= cnt[0];
        res *= 2;
        res += cnt[0] * cnt[0];
        cout << res << "\n";
        return;
    }
    for (int i = 1; i < C; ++i)
        if (a % i == 0 && a / i < C) {
            res += cnt[i] * cnt[a / i];
        }
    cout << res;
}