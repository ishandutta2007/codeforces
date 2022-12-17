#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 5e5;
long long pr[N], dp[N];
set <pair<long long, int> > s;

int main() {
    int i, j, k, n;
    string ss;
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    cin >> ss;
    for (i = 0; i < n; ++i)
        pr[i + 1] = pr[i] + ss[i] - '0';
    int uk = 1;
    for (i = 0; i <= n; ++i) {
        if (i != 0)
            dp[i] = 1e18;
        while (s.size() > 0) {
            pair <long long, int> p = *s.begin();
            if (p.se < i - k)
                s.erase(p);
            else {
                dp[i] = p.fi;
                break;
            }
        }
        if (i != 0)
            dp[i] = min(dp[i], dp[i - 1] + i);
        while (uk <= n && uk <= i + k + 1) {
            if (ss[uk - 1] == '1')
                s.insert({uk + dp[i], uk});
            ++uk;
        }
    }
    cout << dp[n];
}