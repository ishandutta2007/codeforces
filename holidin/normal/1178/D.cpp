#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 2e6 + 1;
const int mod = 998244353;
vector <pair<int, int> > ans;

bool is_p(int x) {
    for (int i = 2; i * i <= x; ++i)
    if (x % i == 0)
        return false;
    return true;
}

int main() {
    int i, j, k, n, w, h;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; ++i)
        ans.push_back({i + 1, (i + 1) % n + 1});
    j = 0;
    while (!is_p(n + j)) {
        ans.push_back({j + 1, n - j - 1});
        ++j;
    }
    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); ++i)
        cout << ans[i].fi << ' ' << ans[i].se << "\n";
}