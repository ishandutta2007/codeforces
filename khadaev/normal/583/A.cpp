#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h, v, hh[60], vv[60];
    cin >> n;
    for (int i = 1; i <= n; ++i) {hh[i] = 0; vv[i] = 0;};
    for (int i = 1; i <= n*n; ++i) {
        cin >> h >> v;
        if (hh[h] == 0 && vv[v] == 0) {
            cout << i << " ";
            hh[h] = 1;
            vv[v] = 1;
            };
        };
    };