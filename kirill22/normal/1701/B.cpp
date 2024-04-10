#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << 2 << '\n';
        vector<int> used(n + 1);
        for (int x = 1; x <= n; x++) {
            int tmp = x;
            while (tmp <= n && !used[tmp]) {
                cout << tmp << " ";
                used[tmp] = 1;
                tmp *= 2;
            }
        }
        cout << '\n';
    }
}