// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
int a[200005], p[200005], e[200005];
bool v[200005];
vector<vector<int>> c;
vector<pair<int, int>> sol;

void work(int x, int y) {
    sol.emplace_back(x, y);
    swap(a[x], a[y]);
    p[a[x]] = x;
    p[a[y]] = y;
    e[a[x]] ^= 1;
    e[a[y]] ^= 1;
}

void solve2(vector<int>& a, vector<int>& b) {
    for (int x : a) {
        work(x, b[0]);
    }

    for (int x : b) {
        if (x != b[0]) {
            work(a[0], x);
        }
    }

    work(a[0], b[0]);
}

void solve1(vector<int>& a) {
    work(a[0], a[1]);
    work(a[1], a[2]);
    work(a[0], a[2]);
    for (int i=3; i<(int)a.size(); i++) {
        work(a[1], a[i]);
    }
    work(a[0], a[1]);
}

void solve3(int x, int y) {
    int z = 1;
    while (z == x || z == y) z++;
    work(y, z);
    work(x, z);
    work(y, z);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }

    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            v[i] = 1;
            vector<int> b = {i};
            for (int x=a[i]; x!=i; x=a[x]) {
                b.push_back(x);
                v[x] = 1;
            }
            if (b.size() > 1) {
                c.push_back(b);
            }
        }
    }

    for (int i=c.size()%2; i<(int)c.size(); i+=2) {
        solve2(c[i], c[i+1]);
    }

    if (c.size() % 2) {
        if (c[0].size() > 2) {
            solve1(c[0]);
        } else {
            solve3(c[0][0], c[0][1]);
        }
    }

    cout << sol.size() << '\n';
    for (auto [x, y] : sol) {
        cout << x << ' ' << y << "\n";
    }

    // for (int i=1; i<=n; i++) {
    //     cerr << a[i] << " \n"[i == n];
    // }
    // for (int i=1; i<=n; i++) {
    //     cerr << e[i] << " \n"[i == n];
    // }
}