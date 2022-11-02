#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int> > v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			v.push_back(make_pair(i, j));
	int p = 1;
	for (int i = 0; i < n; i++) {
		v.push_back(make_pair(p + 1, p + 1));
		v.push_back(make_pair(p + 1, p));
		v.push_back(make_pair(p, p + 1));
		p++;
	}
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << '\n';
	return 0;
}