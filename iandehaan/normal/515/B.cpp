#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int par[210];
int sizes[210];
int getPar(int x) {
	if (par[x] == x) return x;
	return par[x] = getPar(par[x]);
}

void Union(int x, int y) {
	if (getPar(x) == getPar(y)) return;
	sizes[getPar(y)] += sizes[getPar(x)];
	par[getPar(x)] = getPar(y);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	rep(i, 0, 210) {
		par[i] = i;
		sizes[i] = 0;
	}

	int n, m;
	cin >> n >> m;
	int a;
	cin >> a;
	rep(i, 0, a) {
		int x;
		cin >> x;
		sizes[x] = 1;
	}
	int b;
	cin >> b;
	rep(i, 0, b) {
		int x;
		cin >> x;
		sizes[x+n] = 1;
	}

	rep(i, 0, 100'000) {
		Union((i%n), (i%m)+n);
	}

	bool good = true;
	rep(i, 0, n+m) {
		if (sizes[getPar(i)] == 0) good = false;
	}

	if (good) cout << "Yes" << endl;
	else cout << "No" << endl;




}