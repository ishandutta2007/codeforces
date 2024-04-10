#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[1000005];
map<int, basic_string<int>> mp;

int f[1000005];

void add(int x, int v) {
	for (int y=x; y<1000005; y+=y&-y)
		f[y] += v;
}

int get(int x) {
	int v = 0;
	for (int y=x; y; y-=y&-y)
		v += f[y];
	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	for (int i=1; i<=n; i++) {
		mp[a[i]] += i;
		add(i, 1);
	}

	int last = 0, ostalo = n;
	ll sol = 0;


	for (auto& p : mp) {
		sort(p.second.begin(), p.second.end());
		auto it = lower_bound(p.second.begin(), p.second.end(), last);
		rotate(p.second.begin(), it, p.second.end());
		for (int x : p.second) {
			if (x > last) {
				sol += get(x) - get(last);
			} else {
				sol += get(x) - get(last) + ostalo;
			}
			ostalo--;
			last = x;
			add(x, -1);
		}
	}

	cout << sol << '\n';
}