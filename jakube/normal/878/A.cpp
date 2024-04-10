#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> v(10, {0, 1});
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x;
        cin >> x;
        for (int j = 0; j < 10; j++) {
            int b = (x >> j) & 1;
            if (s == "|") {
                v[j].first = v[j].first | b;
                v[j].second = v[j].second | b;
            }
            if (s == "&" || s == "&amp;") {
                v[j].first = v[j].first & b;
                v[j].second = v[j].second & b;
            }
            if (s == "^") {
                v[j].first = v[j].first ^ b;
                v[j].second = v[j].second ^ b;
            }
        }
    }

    cout << 2 << endl;
    int res = 0;
    for (int j = 0; j < 10; j++) {
        if (v[j].first == v[j].second)
            res |= 1 << j;
    }
    cout << "| " << res << endl;
    res = 0;
    for (int j = 0; j < 10; j++) {
        if (v[j].second == 0)
            res |= 1 << j;
    }
    cout << "^ " << res << endl;
}