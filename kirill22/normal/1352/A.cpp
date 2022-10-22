#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a;
        int tmp = 1;
        while (n) {
            if (n % 10 != 0) {
                a.push_back(tmp * (n % 10));
            }
            n /= 10;
            tmp *= 10;
        }
        cout << a.size() << endl;
        for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
        cout << endl;
    }
}