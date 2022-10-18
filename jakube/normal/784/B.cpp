#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 1 << endl;
        return 0;
    }
    
    // 0123456789ABCDEF
    vector<int> circles = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0, 0};

    int cnt = 0;
    while (n) {
        cnt += circles[n % 16];
        n /= 16;
    }
    cout << cnt << endl;
}