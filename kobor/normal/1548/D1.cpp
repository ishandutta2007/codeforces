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

int cnt[4][4];
ll ans;

void solve() {
	int n;
	cin >> n;
	FOR(i, 0, n) {
		int cx, cy;
		cin >> cx >> cy;
		cx %= 4, cy %= 4;
		FOR(ax, 0, 4) FOR(ay, 0, 4) FOR(bx, 0, ax + 1) FOR(by, 0, (ax == bx ? ay + 1 : 4)) {
			int pole = abs(ax * by + bx * cy + cx * ay - ax * cy - bx * ay - cx * by);
			pole = (pole % 4 + 4) % 4;
			pole = 0;
			if(pole == 1 || pole == 3) continue;
			int sum = gcd(ax - bx + 4, ay - by + 4) + gcd(bx - cx + 4, by - cy + 4) + gcd(cx - ax + 4, cy - ay + 4);
			sum %= 4;
			if(sum == 1 || sum == 3) continue;
			if(pole == sum) {
				if(ax == bx && ay == by) ans += cnt[ax][ay] * (cnt[ax][ay] - 1) / 2;
				else ans += cnt[ax][ay] * cnt[bx][by];
			}
		}
		cnt[cx][cy]++;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// int tt; cin >> tt;
	// FOR(te, 0, tt) {
	// 	// cout << "Case #" << te + 1 << ": ";
	// 	solve();
	// }
	solve();
	return 0;
}