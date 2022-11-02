#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int h[300009], b[300009];
long long d[300009];
vector<pair<int, long long> > v;
vector<long long> mp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) {
		long long mx = d[i - 1];
		while (!v.empty() && v.back().first > h[i]) {
			mx = max(mx, v.back().second);
			v.pop_back(); mp.pop_back();
		}
		v.push_back(make_pair(h[i], mx));
		if (mp.empty()) mp.push_back(mx + 1LL * b[i]);
		else mp.push_back(max(mp.back(), mx + 1LL * b[i]));
		d[i] = mp.back();
	}
	cout << d[n] << '\n';
	return 0;
}