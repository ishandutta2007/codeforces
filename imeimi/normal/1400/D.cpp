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
typedef long double lf;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<lf, lf> pff;

int A[3001];
int fen[3001];

void update(int i) {
    while (i <= 3000) {
        ++fen[i];
        i += i & -i;
    }
}

int query(int i) {
    int ret = 0;
    while (i) {
        ret += fen[i];
        i -= i & -i;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        memset(fen, 0, sizeof(fen));
        int n;
        cin >> n;
        vector<pii> P;
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
            for (int j = 1; j < i - 1; ++j) {
                if (A[j] == A[i]) P.emplace_back(j, i);
            }
        }
        reverse(P.begin(), P.end());
        long long ans = 0;
        for (int i = 0, j = 0; i < int(P.size()); ++i) {
            while (j < int(P.size()) && P[j].second > P[i].second) {
                update(P[j++].first);
            }
            ans += query(P[i].second - 1) - query(P[i].first);
        }
        printf("%lld\n", ans);
    }
    return 0;
}