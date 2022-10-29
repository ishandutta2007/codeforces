#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
char c[100];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> c + 1;
        char ch = c[n];
        for (int i = 1; i <= n; i++) cout << ch;
        cout << endl;
    }
}