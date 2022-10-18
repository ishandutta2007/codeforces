#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef double K;
constexpr int INF = 0x3f3f3f3f;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define TRAV(x, a) for(auto &x: (a))
#define SZ(x) ((int)(x).size())
#define PB push_back
#define X first
#define Y second

bool isSquare(int n) {
	int co = sqrt(n);
	return co * co == n;
}

bool check2(int n) {
	if(n % 2 != 0) return 0;
	return isSquare(n / 2);
}

bool check4(int n) {
	if(n % 4 != 0) return 0;
	return isSquare(n / 4);
}

void solve() {
	int n;
	cin >> n;
	cout << (check2(n) || check4(n) ? "YES" : "NO") << '\n';
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