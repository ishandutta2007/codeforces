#include <bits/stdc++.h>
using namespace std;
void work() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = min(c / 2, b);
    b -= ans;
    ans += min(b / 2, a);
    cout << 3 * ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
        work();
    return 0;
}