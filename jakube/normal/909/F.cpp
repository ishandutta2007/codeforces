#include <bits/stdc++.h>
using namespace std;

vector<int> first;

bool f(int x) {
    int m = 1;
    while (m * 2 <= x) {
        m *= 2;
    }

    if (x - m + 1 > m - 1)
        return false;
    
    int up = m;
    int down = m - 1;
    while (up <= x) {
        first[up-1] = down;
        first[down-1] = up;
        up++;
        down--;
    }
    
    if (down > 0) {
        return f(down);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    // = 0
   first.resize(n);
    if (f(n)) {
        cout << "YES" << endl;
        for (auto x : first)
            cout << x << ' ';
        cout << endl;
    } else
        cout << "NO" << '\n';

    // != 0
    if (n <= 5 || __builtin_popcount(n) == 1) {
        cout << "NO" << '\n';
    } else if (n == 6) {
        cout << "YES" << '\n';
        cout << "5 3 2 6 1 4" << endl;
    } else if (n >= 7) {
        cout << "YES" << endl;
        cout << "5 3 2 6 1 7 4 ";
        vector<vector<int>> v(32);
        for (int i = 8; i <= n; i++) {
            v[32 - __builtin_clz(i)].push_back(i);
        }
        for (auto& vv : v) {
            for (int i = 0; i < (int)vv.size(); i++) {
                cout << vv[(i + 1) % vv.size()] << ' ';
            }
        }
        cout << endl;
    }
}