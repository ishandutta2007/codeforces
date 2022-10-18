#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;
    
    int x = min(a, b);

    long long res = 1;
    for (int i = 1; i <= x; i++) {
        res *= i;
    }
    cout << res << endl;
}