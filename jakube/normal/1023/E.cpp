#include <bits/stdc++.h>
using namespace std;

int n;

bool ask(int r1, int c1, int r2, int c2) {
    r1++;
    c1++;
    r2++;
    c2++;
    assert(1 <= r1 && r1 <= r2 && r2 <= n);
    assert(1 <= c1 && c1 <= c2 && c2 <= n);
    assert((r2 - r1) + (c2 - c1) >= n - 1);

    cout << "? " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
    string s;
    cin >> s;
    if (s == "YES")
        return true;
    if (s == "NO")
        return false;
    exit(0);
}

int main() {
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n, -1));

    M[0][0] = 1;
    M[n-1][n-1] = 0;

    // find path from (0, 0) to middle
    vector<pair<int, int>> stack;
    stack.push_back({0, 0});

    string res = "";
    while (n-1 - stack.back().first + n-1 - stack.back().second > n - 1) {
        auto last = stack.back();
        if (ask(last.first + 1, last.second, n-1, n-1)) {
            stack.push_back({last.first + 1, last.second});
            res += "D";
        } else {
            stack.push_back({last.first, last.second + 1});
            res += "R";
        }
    }
    auto middle = stack.back();

    stack.push_back({n-1, n-1});
    string res2 = "";
    while (stack.back() != middle) {
        auto last = stack.back();
        if (ask(0, 0, last.first, last.second - 1)) {
            stack.push_back({last.first, last.second - 1});
            res2 += "R";
        } else {
            stack.push_back({last.first - 1, last.second});
            res2 += "D";
        }
    }
    reverse(res2.begin(), res2.end());
    cout << "! " << res + res2 << endl;
}