#include <iostream>
#include <utility>
using namespace std;

pair<int, int> p[200009];
int ans[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i].first >> p[i].second;
	ans[1] = 1;
	if (p[p[1].first].first == p[1].second || p[p[1].first].second == p[1].second) {
		ans[2] = p[1].first; ans[3] = p[1].second;
	}
	else {
		ans[2] = p[1].second; ans[3] = p[1].first;
	}
	for (int i = 2; i <= n - 2; i++) {
		if (ans[i + 1] == p[ans[i]].first)
			ans[i + 2] = p[ans[i]].second;
		else
			ans[i + 2] = p[ans[i]].first;
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << '\n';
	return 0;
}