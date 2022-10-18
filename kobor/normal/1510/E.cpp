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

typedef pair<pair<K, K>, K> pt;

vector<string> gosc;
vector<pt> pkt;
vi zap;
string akt;
int sum;

pt lacz(pt a, pt b){
	return {{(a.X.X * a.Y + b.X.X * b.Y) / (a.Y + b.Y), (a.X.Y * a.Y + b.X.Y * b.Y) / (a.Y + b.Y)}, a.Y + b.Y};
}

pt daj(int x, int y, int rev){
	if(rev) y--;
	K xx = 1.0 * (3 * y + 2) / (6 * y + 3);
	K yy = 1.0 * (3 * y * (y + 1) + 1) / (6 * y + 3);
	K mass = 1.0 * (2 * y + 1) / 2;
	return {{x + (rev ? 1 - xx : xx), yy}, mass};
}

void gen(int n) {
	if(n == 0) {
		gosc.PB(akt);
		int wys = 0;
		pt jan;
		FOR(i, 0, SZ(akt)) {
			jan = lacz(jan, daj(i, wys, akt[i] == ')'));
			wys += (akt[i] == '(' ? 1 : -1);
		}
		pkt.PB(jan), zap.PB(wys);
		return;
	}
	if(sum > 0) {
		akt += ')';
		sum--;
		gen(n - 1);
		sum++;
		akt.pop_back();
	}
	akt += '(';
	sum++;
	gen(n - 1);
	sum--;
	akt.pop_back();
}


void solve() {
	int n;
	K xk, yk;
	cin >> n >> xk >> yk;
	gen(n / 2);
	constexpr K EPS = 1e-3;
	set<pair<K, int>> ziomy[20];
	FOR(i, 0, SZ(pkt)) {
		ziomy[zap[i]].insert({(xk - (n - pkt[i].X.X)) * pkt[i].Y, i});
	}
	FOR(i, 0, SZ(pkt)) {
		auto beg = ziomy[zap[i]].lower_bound({(pkt[i].X.X - xk) * pkt[i].Y - EPS, 0});
		auto ed = ziomy[zap[i]].lower_bound({(pkt[i].X.X - xk) * pkt[i].Y + EPS, 0});
		for(auto it = beg; it != ed; it++) {
			auto jejku = pkt[(*it).Y];
			jejku.X.X = (n - jejku.X.X);
			auto wyn = lacz(pkt[i], jejku);
			if(abs(xk - wyn.X.X) < 1e-8 && abs(yk - wyn.X.Y) < 1e-8) {
				cout << gosc[i];
				reverse(gosc[(*it).Y].begin(), gosc[(*it).Y].end());
				TRAV(x, gosc[(*it).Y]) x ^= 1;
				cout << gosc[(*it).Y] << '\n';
				return;
			}
		}
	}
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