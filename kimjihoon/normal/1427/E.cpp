#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

vector<pair<long long, pair<char, long long> > > v;

long long ot(long long a, long long b)
{
	v.push_back(make_pair(a, make_pair('^', b)));
	v.push_back(make_pair(a ^ b, make_pair('+', a)));
	v.push_back(make_pair((a ^ b) + a, make_pair('+', b)));
	return (a ^ b) + a + b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	while (n != 1) {
		long long t = 0;
		while ((1LL << (t + 1)) <= n) t++;
		long long pn = n;
		int c = 0;
		for (int i = 0; i < t + 1; i++) {
			v.push_back(make_pair(pn, make_pair('+', pn)));
			pn *= 2;
			c++;
		}
		v.push_back(make_pair(pn, make_pair('+', n)));
		long long p = pn + n, r = ot(n, pn / 2);
		v.push_back(make_pair(r, make_pair('^', p)));
		n = (r ^ p);
	}
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second << '\n';
	}
	return 0;
}