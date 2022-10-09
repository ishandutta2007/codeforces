// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int x;
        cin >> x;

        vector<int> a = { 1 };
        cout << "1\n";

        for (int i=1; i<n; i++) {
            int x;
            cin >> x;
            if (x == 1) {
                a.push_back(1);
            } else {
                int j = a.size() - 1;
                while (a[j] + 1 != x) {
                    j--;
                }
                a[j]++;
                a.erase(a.begin() + j + 1, a.end());
            }
            
            for (int i=0; i<(int)a.size(); i++) {
                cout << a[i] << ".\n"[i == (int)a.size() - 1];
            }
        }
    }
}