#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;

set <int> s;

int main() {
    int i, j, k, n, u, l, t;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int tek = 0;
    long long ans = 0;
    for (i = 0; i < n; ++i) {
        cin >> t;
        if (t == tek)
            ++tek;
        else if (t < tek) {
                ans += tek - t - 1;
                s.insert(-i);
            } else {
                while (t > tek) {
                    if (s.size() == 0)
                        return 2;
                    j = *s.lower_bound(-1e9);
                    s.erase(j);
                    j = -j;
                    ans += i - j;
                    ++tek;
                }
                ++tek;
            }
    }
    cout << ans;
}