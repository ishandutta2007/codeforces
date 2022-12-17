#include <bits/stdc++.h>
using namespace std;
const int N = 1000;

int main() {
    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    int i, j, t, n;
    cin >> n;
    int a = -100000000;
    for (i = 0; i < n; ++i) {
        cin >> t;
        for (j = 0; j * j < t; ++j);
        if (t != j * j)
            a = max(a, t);
    }
    cout << a;

}