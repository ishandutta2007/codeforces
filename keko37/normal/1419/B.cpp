#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

llint t;
vector <llint> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (llint a = 1; a <= 100; a++) {
        llint len = (1LL << a) - 1;
        llint p = len * (len + 1) / 2;
        if (p > 1e18) break;
        v.push_back(p);
    }
    cin >> t;
    while (t--) {
        llint x; cin >> x;
        llint cnt = 0, sum = 0;
        for (auto p : v) {
            sum += p;
            if (sum <= x) cnt++; else break;
        }
        cout << cnt << '\n';
    }
    return 0;
}