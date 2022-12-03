#include <bits/stdc++.h>
using namespace std;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int axb = (a[0] - '0') ^ (b[0] - '0');
        bool f = true;
        for (int i = 1; i < n; ++i) {
            if (axb != ((a[i] - '0') ^ (b[i] - '0'))) {
                f = false;
            }
        }
        if (!f) {
            cout << "NO\n";
            continue;
        }
        int c = 0;
        vector<array<int, 2>> op;
        if (b[0] == '1') {
            op.push_back({2, n});
            b[0] = '0';
            axb ^= 1;
        }
        for (int i = 1; i < n; ++i) {
            if ((b[i] - '0') ^ c) {
                op.push_back({1, i});
                c ^= 1;
                axb ^= 1;
            }
        }
        if (axb) {
            op.push_back({1, n});
        }
        cout << "YES\n";
        cout << op.size() << "\n";
        for (auto elem : op) {
            cout << elem[0] << " " << elem[1] << " " << "\n";
        }
    }
    return 0;
}