#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int cnt = 0;
        if ((a & 1) - (b & 1)) cnt = 1, a++;
        cnt += max(0, b - a);
        cout << cnt << endl;
    }
}