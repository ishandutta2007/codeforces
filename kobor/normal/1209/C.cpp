#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long double K;
constexpr int INF = 0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define X first
#define Y second

void solve() {
    int n;
    string s;
    cin >> n >> s;
    TRAV(x, s) x -= '0';
    FOR(i, 0, 10) {
        vector<bool> color(n);
        bool seen = false;
        FOR(k, 0, n) {
            seen |= s[k] > i;
            color[k] = (s[k] == i ? !seen : s[k] > i);
        }
        vector<int> vec;
        FOR(j, 0, 2) FOR(k, 0, n) if(color[k] == j) vec.PB(s[k]);
        if(is_sorted(vec.begin(), vec.end())) {
            FOR(k, 0, n) cout << color[k] + 1;
            cout << '\n';
            return;
        }
    }
    cout << "-\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	FOR(te, 0, tt) {
		// cout << "Case #" << te + 1 << ": ";
		solve();
	}
	// solve();
	return 0;
}