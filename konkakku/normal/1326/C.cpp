#include <bits/stdc++.h>
using namespace std;

const int N = 2E5 + 5, MOD = 998244353;

int n, k, u;
long long ans = 0, way = 1;
vector<int> pos;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> u;
        if (u + k > n) {
            pos.push_back(i);
            ans += u;
        }
    }
    for (int i = 1; i < k; i++) {
        (way *= pos[i] - pos[i - 1]) %= MOD;
    }
    cout << ans << " " << way;
}