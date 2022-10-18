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

const int N = 2e5 + 5;

set<int> ziomy[N];
int vuln;

void dod() {
	int a, b;
	cin >> a >> b;
	if(b > a && *ziomy[a].rbegin() < a) vuln++;
	ziomy[a].insert(b);
	if(a > b && *ziomy[b].rbegin() < b) vuln++;
	ziomy[b].insert(a);
}

void usu() {
	int a, b;
	cin >> a >> b;
	ziomy[a].erase(b);
	if(b > a && *ziomy[a].rbegin() < a) vuln--;
	ziomy[b].erase(a);
	if(a > b && *ziomy[b].rbegin() < b) vuln--;
}

void solve() {
	int n, m;
	cin >> n >> m;
	FOR(i, 1, n + 1) ziomy[i].insert(-1);
	FOR(i, 0, m) dod();
	int q;
	cin >> q;
	FOR(i, 0, q) {
		int typ;
		cin >> typ;
		if(typ == 1) dod();
		if(typ == 2) usu();
		if(typ == 3) cout << n - vuln << '\n';
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