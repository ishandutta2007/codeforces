#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: a)
#define PB push_back
#define SZ(x) ((int)x.size())
#define X first
#define Y second
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
constexpr int INF = 0x3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi cnt(26);
    TRAV(x, s) cnt[x - 'a']++;
    string ans(k, 'a');
    FOR(i, 0, 26) TRAV(x, ans)
        if(x < 'a' + n / k && x == i + 'a' && cnt[i] > 0) cnt[i]--, x++;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    FOR(te, 0, tt) solve();
    // solve();
    return 0;
}