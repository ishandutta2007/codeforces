#include <bits/stdc++.h>

using namespace std;

int roundup(int x, int c) {
    if(!(x%c)) return x;
    return x + c - (x%c);
}

int main() {
    int n, c, c2, ans = 999099, k;
    cin >> n >> c2;
    for(int i = 1; i <= n; i++) {
        c = c2;
        int x, y;
        cin >> x >> y;
        if(c >= x) {
            c -= x;
            c = roundup(c, y);
            c += x;
            if(ans > c) {
                ans = c;
                k = i;
            }
        }
        else if(ans > x) {
            ans = x;
            k = i;
        }
    }
    cout << k << '\n';
}