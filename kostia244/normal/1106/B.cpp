#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<long long>
#define pi pair<long long, long long>
#define ll long long
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long n, m, f, t, d, val;
vi a, c;
set<pi> s;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	a.resize(n);
	c.resize(n);
	for (auto& i : a)
		cin >> i;
	for (auto& i : c)
		cin >> i;
	for (int i = 0; i < n; i++)
		s.insert(mp(c[i], i));
	while (m--) {
		cin >> t >> d;
		t--;
		long long bill = 0;
		val = min(a[t], d);
		bill += val * c[t];
		a[t] -= val;
		d -= val;
		while (d) {
			if (s.empty())
				break;
			val = min(a[s.begin()->second], d);
			bill += val * (s.begin()->first);
			a[s.begin()->second] -= val;
			d -= val;
			if (a[s.begin()->second] == 0)
				s.erase(s.begin());
		}
		if (d)
			cout << "0\n";
		else
			cout << bill << "\n";
	}
}