#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) {
            cin >> ai;
        }
        int cnt = 0;
        while (a.size() > 1) {
            if (a[a.size() - 2] == 0) {
                a = {a.back()};
                break;
            }
            if (a.size() >= 3 and a[a.size() - 3] == 0) {
                int x = a[a.size() - 2], y  = a[a.size() - 1];
                for (int i = 0; i < a.size() - 2; i += 1) {
                    y = y - x;
                    if (x > y) swap(x, y);
                }
                a = {x, y};
                continue;
            } 
            vector<int> b;
            for (int i = 1; i < a.size(); i += 1)
                b.push_back(a[i] - a[i - 1]);
            sort(b.begin(), b.end());
            a.swap(b);
        }
        cout << a[0] << "\n"; 
    }
    return 0;
}