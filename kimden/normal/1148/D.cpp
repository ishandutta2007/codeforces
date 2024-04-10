#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

struct par {
    int a, b, idx;
    par(int a = 0, int b = 0, int idx = -1): a(a), b(b), idx(idx) {}
    bool operator < (par& rhs) {
        if (b > a)
            return a > rhs.a;
        return a < rhs.a;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<par> a[2];
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        par p(x, y, i + 1);
        a[x < y ? 0 : 1].push_back(p);
    }
    int state = a[0].size() > a[1].size() ? 0 : 1;
    sort(a[state].begin(), a[state].end());
    cout << a[state].size() << "\n";
    for (int i = 0; i < a[state].size(); ++i) {
        cout << a[state][i].idx << " ";
    }
    cout << "\n";
}