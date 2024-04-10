#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<long long, long long> > v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long n, b; cin >> n >> b;
	for (long long i = 2; i * i <= b; i++)
		if (b % i == 0) {
			if (v.size() > 0 && v.back().first == i)
				v.back().second++;
			else
				v.push_back(make_pair(i, 1));
			b /= i; i = 1;
		}
	if (b > 1) {
		if (v.size() > 0 && v.back().first == b)
			v.back().second++;
		else
			v.push_back(make_pair(b, 1));
	}
	long long ans = 0;
	for (int i = 0; i < v.size(); i++) {
		long long c = 0, t = v[i].first;
		while (t <= n) {
			c += n / t;
			if (t > n / v[i].first) break;
			t *= v[i].first;
		}
		if (i == 0) ans = c / v[i].second;
		else ans = min(ans, c / v[i].second);
	}
	cout << ans << '\n';
	return 0;
}