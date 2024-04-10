#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int t, a, b;

int calc (int x, int y) {
    if (y == 1) return 2e9;
    int res = 0;
    while (x > 0) {
        res++;
        x /= y;
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        int sol = 2e9;
        for (int i = 0; i <= 30; i++) {
            sol = min(sol, i + calc(a, b + i));
        }
        cout << sol << '\n';
    }
    return 0;
}