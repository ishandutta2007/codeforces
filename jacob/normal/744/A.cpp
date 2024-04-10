#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> s;
vector<int> ss;

int get(int p) {
	if (s[p] == p)
		return p;
	return s[p] = get(s[p]);
}

void un(int p1, int p2) {
	p1 = get(p1);
	p2 = get(p2);
	if (p1 == p2)
		return;
	if (ss[p1] < ss[p2])
		swap(p1, p2);
	ss[p1] += ss[p2];
	s[p2] = p1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	s.resize(n);
	ss.resize(n, 1);
	for (int i = 0; i < n; ++i) {
		s[i] = i;
	}
	vector<int> caps(k);
	for (int i = 0; i < k; ++i) {
		cin >> caps[i];
		--caps[i];
	}
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		un(x, y);
	}
	int max_cap = 0;
	int sum_cap = 0;
	int res = 0;
	for (int i = 0; i < k; ++i) {
		int t = ss[get(caps[i])];
		max_cap = max(max_cap, t);
		sum_cap += t;
		res += t * (t - 1) / 2;
	}
	int fr = n - sum_cap;
	res += fr * (fr - 1) / 2;
	res += fr * max_cap;
	cout << res - m << endl;
}