#include<bits/stdc++.h>
 
using namespace std;

void solve(vector<array<int, 4>> a) {
    set<pair<int, int>> c;
    auto b = a;
    sort(a.begin(), a.end(), [&] (const array<int, 4>& x, const array<int, 4>& y) {
        return x[0] < y[0];
    });
    sort(b.begin(), b.end(), [&] (const array<int, 4>& x, const array<int, 4>& y) {
        return x[1] < y[1];
    });
    int j = 0;
    for (auto mas : a) {
        while (j < (int) b.size() && b[j][1] < mas[0]) {
            int l = b[j][2], r = b[j][3];
            j++;
            while (1) {
                auto it = c.lower_bound(make_pair(l, l));
                if (it != c.end() && (*it).second <= r) {
                    c.erase(it);
                } else {
                    break;
                }
            }
            auto it = c.lower_bound(make_pair(l, l));
            if (it != c.end()) {
                auto g = *it;
                if (g.first <= r) {
                    r = g.first - 1;
                }
            } else if (it != c.begin()) {
                it = prev(it);
                auto g = *it;
                if (g.second >= l) {
                    l = g.second + 1;
                }
            }
            if (l <= r) {
                c.insert({l, r});
            }
        }
        auto it = c.lower_bound(make_pair(mas[2], mas[2]));
        if (it != c.end() && (*it).first <= mas[3]) {
            cout << "NO";
            exit(0);
        }
        if (it != c.begin() && (*--it).second >= mas[2]) {
            cout << "NO";
            exit(0);
        }
    }
} 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<array<int, 4>> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a[i][j];
        }
    }
    solve(a);
    for (int i = 0; i < n; i++) {
        swap(a[i][0], a[i][2]);
        swap(a[i][1], a[i][3]);
    }
    solve(a);
    cout << "YES";
}