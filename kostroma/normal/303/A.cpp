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
    //cin >> t;
    while (t--)
        solve();
    return 0;
}

//#define int li
int n;
void solve() {
    cin >> n;
    if (n % 2 == 0) {
        cout << "-1";
        return;
    }
    if (n & 1) {
        for (int i = 0; i < n; ++i)
            cout << i << ' ';
        cout << endl;
        for (int i = 0; i < n; ++i)
            cout << i << ' ';
        cout << endl;
        for (int i = 0; i < n; ++i)
            cout << (2 * i) % n << ' ';
        cout << endl;
        return;
    }
    for (int i = 0; i < n; ++i)
        cout << i << ' ';
    cout << endl;
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            cout << (n / 2 + i / 2) << ' ';
        }
        else {
            cout << i / 2 << ' ';
        }
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            cout << (i + n / 2 + i / 2) % n << ' ';
        }
        else {
            cout << (i / 2 + i) % n << ' ';
        }
    }
}