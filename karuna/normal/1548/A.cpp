#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long lint;
typedef pair<int, int> pint;

const int M = 2e5 + 10;
int n, m;
set<int, greater<int>> St[M];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        St[x].insert(y); St[y].insert(x);
    }
    int Count = 0;
    for (int i = 1; i <= n; i++) {
        if (St[i].empty() || *St[i].begin() < i) Count += 1;
    }
    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 3) {
            cout << Count << '\n';
        }
        if (t == 1) {
            int x, y; cin >> x >> y;

            if (St[x].empty() || *St[x].begin() < x) Count -= 1;
            St[x].insert(y); 
            if (*St[x].begin() < x) Count += 1;

            if (St[y].empty() || *St[y].begin() < y) Count -= 1;
            St[y].insert(x);
            if (*St[y].begin() < y) Count += 1;
        }
        if (t == 2) {
            int x, y; cin >> x >> y;

            if (*St[x].begin() < x) Count -= 1;
            St[x].erase(y);
            if (St[x].empty() || *St[x].begin() < x) Count += 1;

            if (*St[y].begin() < y) Count -= 1;
            St[y].erase(x);
            if (St[y].empty() || *St[y].begin() < y) Count += 1;
        }
    }
}