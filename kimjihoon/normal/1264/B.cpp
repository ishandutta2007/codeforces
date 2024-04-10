#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans;
int n = 0, a[4];

void ps(int s, bool f)
{
	if (ans.size() == n) return;
	ans.clear();
	int r[4], p = s;
	for (int i = 0; i < 4; i++) r[i] = a[i];
	while (0 <= p && p < 4 && r[p]) {
		r[p]--; 
		if (f) ans.push_back(3 - p);
		else ans.push_back(p);
		if (p > 0 && r[p - 1]) p--;
		else p++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 4; i++) {
		cin >> a[i]; n += a[i];
	}
	ps(0, false); ps(1, false);
	reverse(a, a + 4);
	ps(0, true); ps(1, true);
	if (ans.size() < n) cout << "NO" << '\n';
	else {
		cout << "YES" << '\n';
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
	return 0;
}