#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t += 1)
        [&](){
            int n, k;
            cin >> n >> k;
            vector<int> a(n);
            for (int& ai : a) cin >> ai;
            if (ranges::count(a, 1))
                cout << "YES\n";
            else cout << "NO\n";
        }();
}