#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, p;
    cin >> n >> p;
    for (int i = 0; i <= 100; ++i)
        if ((n - p * i) >= 0) {
            int x = __builtin_popcount(n - p * i);
            if (x <= i && i <= n - p * i) {
                cout << i << endl;
                return 0;
            }
        }
    cout << -1 << endl;
    return 0;
}