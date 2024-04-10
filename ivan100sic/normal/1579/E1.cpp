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
        deque<int> a;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            if (a.empty()) a.push_back(x);
            else if (x < a.front()) a.push_front(x);
            else a.push_back(x);
        }

        for (int x : a) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}