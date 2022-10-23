#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1)
        [&](){
            int n;
            cin >> n;
            vector<int> a(n + 1), p(n + 1);
            for (int i = 1; i <= n; i += 1) {
                cin >> a[i];
                p[a[i]] = i;
            }
            for (int i = 1; i <= n; i += 1)
                cout << p[n + 1 - i] << " ";
            cout << "\n";
        }();
}