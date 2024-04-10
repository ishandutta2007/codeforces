#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a[1100];
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int turns = 0, det = 0;
    while(true) {
        for (int j = 0; j < n; ++j)
            if (a[j] <= det) {
                ++det;
                a[j] = 6666;
                };
        if (det == n) break;
        ++turns;
        for (int j = n - 1; j >= 0; --j)
            if (a[j] <= det) {
                ++det;
                a[j] = 6666;
                };
        if (det == n) break;
        ++turns;
        };
    cout << turns;
    };