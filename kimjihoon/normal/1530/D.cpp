#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[200009], p[200009];
bool vs[200009];
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			vs[i] = false;
			p[i] = 0;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (!vs[a[i]]) {
				vs[a[i]] = true;
				p[i] = a[i];
				ans++;
			}
		}
		v.clear();
		for (int i = 1; i <= n; i++)
			if (!vs[i])
				v.push_back(i);
		int pi = 0, r = v.size(), ri = 0;
		for (int i = 1; i <= n && pi < r; i++) {
			if (!p[i]) {
				if (i == v[pi]) {
					r--;
					p[i] = v[r];
				}
				else {
					p[i] = v[pi];
					pi++;
				}
				if (i == p[i]) ri = i;
			}
		}
		if (ri) {
			for (int i = 1; i <= n; i++) 
				if (i != ri && (p[i] != a[i] || p[i] == a[ri])) {
					swap(p[ri], p[i]);
					break;
				}
		}
		cout << ans << '\n';
		for (int i = 1; i <= n; i++)
			cout << p[i] << " ";
		cout << '\n';
	}
	return 0;
}