#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

#define ll long long

const int maxn = 1 << 17;

int x[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int n;
    while (cin >> n) {
        int a = 0, b = 0, c = 0;
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            cin >> x[i];
            if (x[i] == 25) {
                a++;
            }
            if (x[i] == 50) {
                if (a < 1) ok = 0;
                a--;
                b++;
            }
            if (x[i] == 100) {
                if (!b) {
                    if (a < 3) {
                        ok = 0;
                    }
                    a -= 3;
                } else {
                    b--;
                    if (a < 1) {
                        ok = 0;
                    }
                    a--;
                }
                c++;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}