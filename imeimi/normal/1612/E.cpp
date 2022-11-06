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
typedef long long ll;
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<lf, lf> pff;

int n;
int M[200005], K[200005];
int S[200005];
ll B[200005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> M[i] >> K[i];
    for (int c = 1; c <= 20 && c <= n; ++c) {
        memset(S, 0, sizeof(S));
        for (int i = 1; i <= n; ++i) S[M[i]] += min(K[i], c);
        sort(S + 1, S + 200001);
        for (int i = 0; i < c; ++i) B[c] += S[200000 - i];
    }
    for (int c = 21; c <= n; ++c) {
        B[c] = B[c - 1] + S[200001 - c];
    }
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
        if (B[ans] * i < B[i] * ans) ans = i;
    }
    memset(S, 0, sizeof(S));
    for (int i = 1; i <= n; ++i) S[M[i]] += min(K[i], ans);
    vector<pii> P;
    for (int i = 1; i <= 200000; ++i) {
        P.emplace_back(S[i], i);
    }
    sort(P.rbegin(), P.rend());
    printf("%d\n", ans);
    for (int i = 0; i < ans; ++i) printf("%d ", P[i].second);
    return 0;
}