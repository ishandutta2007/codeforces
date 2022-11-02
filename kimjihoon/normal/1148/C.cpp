#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int n, p[300009], r[300009];
vector<pair<int, int> > v;

void sp(int a, int b)
{
	v.push_back(make_pair(a, b));
	swap(p[a], p[b]); swap(r[p[a]], r[p[b]]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		r[p[i]] = i;
	}
	for (int i = 2; i < n; i++) {
		if (i == p[i]) continue;
		int a, b;
		if (r[i] <= n / 2) a = n;
		else a = 1;
		if (i <= n / 2) b = n;
		else b = 1;
		if (a == b) {
			sp(r[i], b);
			sp(b, i);
		}
		else {
			sp(r[i], a);
			sp(1, n);
			sp(i, b);
		}
	}
	if (p[1] != 1) sp(1, n);
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << '\n';
	return 0;
}