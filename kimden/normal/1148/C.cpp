#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int n;
vector<int> a, b;
vector<pii> ans;

void swp(int i, int j) {
    if (i == j) {
        return;
    }
    if (abs(i - j) < n / 2) {
        throw;
    }
//cerr << i << " " << j << endl;
    ans.emplace_back(i + 1, j + 1);
    swap(a[i], a[j]);
    swap(b[a[i]], b[a[j]]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        b[a[i]] = i;
    }
    int half = n / 2;
    for (int i = n / 2 - 1; i >= 0; --i) {
        int q = i;
        int w = n - 1 - i;
        if (b[q] >= half) {
            swp(0, b[q]);
        }
        swp(b[q], n - 1);
        swp(n - 1, q);
        if (b[w] < half) {
            swp(n - 1, b[w]);
        }
        swp(b[w], 0);
        swp(0, w);
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}