#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, y;
    cin >> n >> y;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int m, y2;
    cin >> m >> y2;
    vector<int> b(m);
    for (auto& x : b)
        cin >> x;
    
    int best = min(2, n + m);
    for (int l = 0; l < 30; l++) {
        int MOD = 1 << l;
        map<int, int> ma;
        for (int x : a)
            ma[x % (2*MOD)]++;
        for (int x : b)
            ma[(x + MOD) % (2*MOD)]++;

        for (auto [_, c] : ma)
            best = max(best, c);
    }
    cout << best << endl;
}