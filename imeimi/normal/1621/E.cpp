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

struct rational {
    ll b, a;
    rational(ll b, ll a) : b(b), a(a) {}
    bool operator<(rational r) const {
        return b * r.a < a * r.b;
    }
};

int n, m;
int A[100005];
vector<int> B[100005];
ll S[100005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) cin >> A[i];
        sort(A + 1, A + n + 1);
        vector<rational> avg;
        for (int i = 1; i <= m; ++i) {
            int k;
            cin >> k;
            B[i] = vector<int>(k);
            S[i] = 0;
            for (int &j : B[i]) cin >> j, S[i] += j;
            avg.emplace_back(S[i], k);
        }
        sort(avg.rbegin(), avg.rend());
        set<rational> exact, need;
        bool all_pos = true;
        for (int i = n, j = 0; i >= 1; --i) {
            while (j < m && rational(A[i], 1) < avg[j]) ++j;
            if (j == n - i) exact.emplace(A[i], 1);
            else if (j == n - i + 1) need.emplace(A[i], 1);
            else if (j > n - i + 1) all_pos = false;
        }
        string ans = "";
        for (int i = 1; i <= m; ++i) {
            for (int j : B[i]) {
                if (!all_pos) {
                    ans.push_back('0');
                    continue;
                }
                rational prev = rational(S[i], int(B[i].size()));
                rational next = rational(S[i] - j, int(B[i].size()) - 1);
                bool pos = true;
                auto it1 = exact.lower_bound(prev);
                if (it1 != exact.end() && *it1 < next) pos = false;
                auto st = need.begin();
                auto ed = need.rbegin();
                if (need.empty() || !(*st < next) && *ed < prev);
                else pos = false;
                ans.push_back(pos ? '1' : '0');
            }
        }
        printf("%s\n", ans.c_str());
    }
    return 0;
}