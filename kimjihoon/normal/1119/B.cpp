#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int h, a[1009], d[1009];
vector<int> p;

bool ps(int k)
{
	p.clear(); p.push_back(0);
	for (int i = 1; i <= k; i++)
		p.push_back(a[i]);
	sort(p.begin(), p.end());
	d[1] = p[1];
	bool ans = true;
	for (int i = 2; i <= k; i++) {
		d[i] = min(d[i - 2], d[i - 1]) + p[i];
		if (d[i] > h) {
			ans = false;
			break;
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n >> h;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (!ps(i)) {
			cout << i - 1 << '\n';
			return 0;
		}
	}
	cout << n << '\n';
	return 0;
}