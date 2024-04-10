#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<long long> v;
priority_queue<long long> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		long long s = 0;
		while (!q.empty()) q.pop();
		for (int i = 1; i <= n; i++) {
			long long a; cin >> a;
			q.push(a);
			s += a;
		}
		v.clear();
		v.push_back(0); v.push_back(1);
		s--;
		while (s > 0) {
			long long t = v.back() + v[(int)v.size() - 2];
			v.push_back(t);
			s -= v.back();
		}
		if (s < 0) {
			cout << "NO" << '\n';
			continue;
		}
		bool f = true;
		long long pr = 0;
		while (!v.empty()) {
			long long t = v.back(); v.pop_back();
			if (!t) break;
			if (q.empty() || q.top() < t) {
				f = false;
				break;
			}
			t = q.top() - t;
			q.pop(); 
			if (pr) q.push(pr);
			pr = t;
		}
		if (f) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}