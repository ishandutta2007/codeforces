#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;
const int MOD = 998244353;

llint t, n;
llint a[MAXN], sum[MAXN];
vector <llint> evn, odd;

llint solve (int L, int R, llint ofs) {
    if (L > R) return ofs > 0;
    evn.clear(); odd.clear();
    evn.push_back(0);
    odd.push_back(0);
    for (int i = L; i <= R; i++) {
        if (i % 2 == 0) evn.push_back(evn.back() + a[i] * 2);
        if (i % 2 == 1) odd.push_back(odd.back() + a[i] * 2);
    }
    llint E = evn.back() / 2, O = odd.back() / 2;
    llint res = 0;
    for (auto val : evn) {
        res += lower_bound(odd.begin(), odd.end(), E + O + ofs - val) - odd.begin();
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        llint sol = 1;
        if (n >= 2) sol += solve(2, n - 1, a[n] - a[1]);
        if (n >= 3) sol += solve(2, n - 2, a[n - 1] - a[n] - a[1]);
        if (n >= 3) sol += solve(3, n - 1, a[1] + a[n] - a[2]);
        if (n >= 4) sol += solve(3, n - 2, a[1] + a[n - 1] - a[2] - a[n]);
        if (n == 2) sol += solve(2, 1, a[1] - a[2]);
        if (n >= 3) {
            for (int i = 1; i < n; i++) {
                if (sum[i] - (sum[n] - sum[i]) > 0) sol++;
            }
        }
        cout << sol % MOD << '\n';
    }
    return 0;
}