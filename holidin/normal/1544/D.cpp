#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <algorithm>
#include <set>
#include <math.h>
#include <random>
#include <bitset>
#include <map>
#include <unordered_map>
#include <queue>
#include <time.h>
#define fi first
#define se second
#define ll long long
#define int long long
#define ld double
#define mp make_pair
using namespace std;
const int inf = 1e15;
const int N = 1e6 + 13;
mt19937 rnd;

int b[N];
int c[N];
bool use[N];
void solve(int num) {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i)
        c[i] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        c[v[i]] = 1;
        b[i] = -1;
        use[i] = 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    if (c[i] == 0) {
        int x = i;
        while (!use[v[x]] && c[x] == 0) {
            b[x] = v[x];
            use[v[x]] = 1;
            x = v[x];
            ++cnt;
        }
    }
    for (int i = 1; i <= n; ++i)
        if (b[i] == -1 && !use[v[i]]) {
            b[i] = v[i];
            use[v[i]] = 1;
            ++cnt;
        }
    vector<int> f1, f2;
    for (int i = 1; i <= n; ++i)
        if (b[i] == -1) {
            f1.push_back(i);
        }
    for (int i = 1; i <= n; ++i)
        if (!use[i]) {
            f2.push_back(i);
        }
    if (f1.size() == 1 && f2.size() == 1 && f1[0] == f2[0]) {
        exit(1);
    }
    if (f1.size() != f2.size()) {
        exit(2);
    }
    while (f1.size() > 0) {
        if (f1.back() == f2.back()) {
            swap(f1.back(), f1[f1.size() - 2]);
        }
        if (f1.size() == 2 && f1[0] == f2[0]) {
            swap(f1[0], f1[1]);
        }
        b[f1.back()] = f2.back();
        f1.pop_back();
        f2.pop_back();
    }
    cout << cnt << "\n";
    for (int i = 1; i <= n; ++i)
        cout << b[i] << ' ';
    cout << "\n";

}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // local
    int test = 1;
    cin >> test;
    int cnt = 0;
    while (test--) {
        ++cnt;
        solve(cnt);
    }

}