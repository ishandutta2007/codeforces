#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        set<int> s;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            s.insert(a);
        }
        int i = 0;
        for (i = 1; i <= 1050; i++) {
            if (x == 0 && !s.count(i))
                break;
            else if (!s.count(i)) {
                x--;
            }
        }
        cout << i - 1 << endl;
    }
}