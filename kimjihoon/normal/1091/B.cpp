#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int n;
pair<int, int> pa[1009], pb[1009], pr[1009];

bool ch(int x, int y)
{
	for (int i = 0; i < n; i++)
		pr[i] = make_pair(x - pa[i].first, y - pa[i].second);
	sort(pr, pr + n);
	for (int i = 0; i < n; i++)
		if (pr[i] != pb[i])
			return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> pa[i].first >> pa[i].second;
	for (int i = 0; i < n; i++)
		cin >> pb[i].first >> pb[i].second;
	sort(pb, pb + n);
	for (int i = 0; i < n; i++) {
		int x = pa[0].first + pb[i].first, y = pa[0].second + pb[i].second;
		if (ch(x, y)) {
			cout << x << " " << y << '\n';
			break;
		}
	}
	return 0;
}