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

int n, A[200005];
vector<int> L[200005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i <= n; ++i) L[i].clear();
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
            L[A[i]].push_back(i);
        }
        for (int i = 0; i <= n; ++i) {
            reverse(L[i].begin(), L[i].end());
        }
        vector<int> ans;
        for (int s = 1; s <= n; ++s) {
            int p = s;
            for (int i = 0; i <= n; ++i) {
                if (L[i].empty()) {
                    ans.push_back(i);
                    break;
                }
                s = max(s, L[i].back());
            }
            for (int i = p; i <= s; ++i) L[A[i]].pop_back();
        }
        printf("%d\n", int(ans.size()));
        for (int i : ans) printf("%d ", i);
        printf("\n");
    }
    return 0;
}