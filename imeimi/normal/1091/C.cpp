#include <iostream>
#include <algorithm>
#include <vector>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

vector<llong> ans;
int n;
void solve(int g) {
    llong m = n / g;
    ans.push_back(m * (m - 1) / 2 * g + m);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i != 0) continue;
        solve(i);
        if (i * i != n) solve(n / i);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (llong i : ans) printf("%lld ", i);
    return 0;
}