#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

int n, rip;
vector <pi> v[2], r;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v[(i + j) % 2].push_back({i, j});
        }
    }
    while (v[0].size() > 0 && v[1].size() > 0) {
        int a; cin >> a;
        if (a != 1) {
            cout << 1 << " " << v[0].back().first << " " << v[0].back().second << endl;
            v[0].pop_back();
        } else {
            cout << 2 << " " << v[1].back().first << " " << v[1].back().second << endl;
            v[1].pop_back();
        }
    }
    if (v[0].size() == 0) {
        r = v[1];
        rip = 1;
    } else {
        r = v[0];
        rip = 2;
    }
    while (r.size() > 0) {
        int a, b; cin >> a;
        for (int i = 1; i <= 3; i++) {
            if (i != a && i != rip) {
                b = i;
                break;
            }
        }
        cout << b << " " << r.back().first << " " << r.back().second << endl;
        r.pop_back();
    }
    return 0;
}