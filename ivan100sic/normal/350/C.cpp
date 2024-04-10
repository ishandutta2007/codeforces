#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
pair<int, int> a[100005];
vector<string> sol;
int x, y;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return abs(a.first) + abs(a.second) < abs(b.first) + abs(b.second);
}

void go(int tx, int ty) {
	if (x < tx)
		sol.push_back(string("1 ") + to_string(tx-x) + " R");
	if (x > tx)
		sol.push_back(string("1 ") + to_string(x-tx) + " L");
	if (y < ty)
		sol.push_back(string("1 ") + to_string(ty-y) + " U");
	if (y > ty)
		sol.push_back(string("1 ") + to_string(y-ty) + " D");
	x = tx;
	y = ty;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i].first >> a[i].second;

	sort(a, a+n, cmp);
	for (int i=0; i<n; i++) {
		go(a[i].first, a[i].second);
		sol.push_back("2");
		go(0, 0);
		sol.push_back("3");
	}
	cout << sol.size() << '\n';
	for (auto s : sol)
		cout << s << '\n';
}