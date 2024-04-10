#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m, z;
    cin >> n >> m >> z;
    
    int cnt = 0;
    for (int i = 1; i <= z; i++) {
        if (i % n == 0 && i % m == 0)
            cnt++;
    }

    cout << cnt << endl;

    return 0;
}