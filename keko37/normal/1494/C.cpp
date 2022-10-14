#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;
typedef vector <int> vi;

const int MAXN = 200005;

int t;
int sum[MAXN];

int solve (vi a, vi b) {
    if (a.empty() || b.empty()) return 0;
    int n = a.size(), m = b.size();
    sum[n] = 0;
    for (int i = n-1; i >= 0; i--) {
        sum[i] = sum[i + 1];
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        if (it != b.end() && *it == a[i]) sum[i]++;
    }
    vi tmp;
    for (int i = 0; i < n; i++) {
        tmp.push_back(a[i] - i);
    }
    int res = 0;
    for (int i = 0; i < m; i++) {
        int br = upper_bound(tmp.begin(), tmp.end(), b[i]) - tmp.begin();
        if (br == 0) continue;
        int val = upper_bound(b.begin(), b.end(), b[i] + br - 1) - b.begin() - i;
        val += sum[br];
        res = max(res, val);
    }
    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vi poza, pozb, nega, negb;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a > 0) poza.push_back(a); else nega.push_back(-a);
        }
        for (int i = 0; i < m; i++) {
            int b; cin >> b;
            if (b > 0) pozb.push_back(b); else negb.push_back(-b);
        }
        reverse(nega.begin(), nega.end());
        reverse(negb.begin(), negb.end());
        cout << solve(poza, pozb) + solve(nega, negb) << '\n';
    }
    return 0;
}