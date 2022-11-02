#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> d[100009];
vector<int> v[200009];
int a[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d[i].first; d[i].second = i;
	}
	sort(d, d + n); reverse(d, d + n);
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (a[j] != 0) j++;
		a[j] = d[i].second * 2 + 1;
		if (j >= d[i].first - 1) v[j - d[i].first + 1].push_back(d[i].second * 2 + 2);
		else {
			int p = j + d[i].first;
			if (a[p] == 0) a[p] = d[i].second * 2 + 2;
			else v[p - 1].push_back(d[i].second * 2 + 2);
		}
	}
	j = 0;
	while (a[j] != 0) {
		if (a[j + 1] != 0) cout << a[j] << " " << a[j + 1] << '\n';
		for (int i = 0; i < v[j].size(); i++)
			cout << a[j] << " " << v[j][i] << '\n';
		j++;
	}
	return 0;
}