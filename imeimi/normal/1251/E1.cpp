#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n;
vector<int> P[200001];
int S[200001];
llong solve() {
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        P[i].clear();
        S[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        int m, p;
        cin >> m >> p;
        P[m].push_back(p);
        ++S[m + 1];
    }
    for (int i = 1; i <= n; ++i) {
        S[i] += S[i - 1];
    }
    int inc = 0;
    llong ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = n - 1; i > 0; --i) {
        for (int j : P[i]) pq.push(j);
        while (S[i] + inc < i) {
            ans += pq.top();
            ++inc;
            pq.pop();
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) printf("%lld\n", solve());
    return 0;
}