#include "bits/stdc++.h"

using namespace std;

map<pair<int, int>, int> res;
map<pair<int, int>, pair<int, int>> dp;

int dfs(int a, int b) {
    //cout << a << " " << b << endl;
    if (a + b <= 2) {
        return res[{a, b}] = 0;
    }
    if (res.find({a, b}) != res.end()) {
        return res[{a, b}];
    }
    int opt = (int) 1e9;
    pair<int, int> optxy;
    int midx = a / 2, midy = b / 2;
    for (auto x : {midx - 1, midx, midx + 1}) {
        for (auto y : {midy - 1, midy, midy + 1}) {
            if (x < 0 || y < 0 || (x == a && y == b) || x > a || y > b) {
                continue;
            }
            pair<int, int> first = {x + y, a - x};
            pair<int, int> second = {a - x + b - y, x};
            //cout << first.first << " " << first.second << endl;
            //cout << second.first << " " << second.second << endl;
            if (first.first + first.second >= a + b && first.second <= b) {
                continue;
            }
            if (second.first + second.second >= a + b && second.second <= b) {
                continue;
            }
            int result = max(dfs(first.first, first.second), dfs(second.first, second.second)) + 1;
            if (result < opt) {
                opt = result;
                optxy = {x, y};
            }
        }
    }
    dp[{a, b}] = optxy;
    return res[{a, b}] = opt;
}

int ask(const vector<int>& a) {
    cout << "? " << (int) a.size() << " ";
    for (auto x : a) {
        cout << x << " ";
    }
    cout << endl;
    string res;
    cin >> res;
    return res == "YES" ? 1 : 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    dfs(n, 0);
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        a.push_back(i);
    }
    while ((int) a.size() + (int) b.size() > 2) {
        auto [x, y] = dp[{(int) a.size(), (int) b.size()}];
        assert(x + y > 0);
        vector<int> c;
        for (int i = 0; i < x; i++) {
            c.push_back(a[i]);
        }
        for (int i = 0; i < y; i++) {
            c.push_back(b[i]);
        }
        vector<int> ta, tb;
        if (ask(c)) {
            ta = c;
            for (int i = x; i < (int) a.size(); i++) {
                tb.push_back(a[i]);
            }
        } else {
            for (int i = x; i < (int) a.size(); i++) {
                ta.push_back(a[i]);
            }
            for (int i = y; i < (int) b.size(); i++) {
                ta.push_back(b[i]);
            }
            for (int i = 0; i < x; i++) {
                tb.push_back(a[i]);
            }
        }
        swap(a, ta);
        swap(b, tb);
    }
    for (auto x : a) {
        cout << "! " << x << endl;
        string res;
        cin >> res;
        if (res == ":)") {
            return 0;
        }
    }
    for (auto x : b) {
        cout << "! " << x << endl;
        string res;
        cin >> res;
        if (res == ":)") {
            return 0;
        }
    }
}