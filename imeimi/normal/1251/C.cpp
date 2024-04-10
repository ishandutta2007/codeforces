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

char A[300001];
void solve() {
    cin >> A;
    int n = strlen(A);
    vector<int> C[2];
    for (int i = 0; i < n; ++i) {
        C[A[i] & 1].push_back(A[i]);
    }
    vector<char> ans;
    for (int i = 0, j = 0; i + j < n; ) {
        if (j >= (int)C[1].size() || (i < (int)C[0].size() && C[0][i] < C[1][j])) {
            ans.push_back(C[0][i++]);
        }
        else {
            ans.push_back(C[1][j++]);
        }
    }
    ans.push_back(0);
    printf("%s\n", ans.data());
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}