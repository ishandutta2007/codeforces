#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, a[109], ta[109], r[109];
vector<int> v;
vector<vector<int> > ans;

void pp()
{
	int s = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = s; j < s + v[i]; j++) 
			ta[n - s - v[i] + j - s] = a[j];
		s += v[i];
	}
	for (int i = 0; i < n; i++) {
		a[i] = ta[i];
		r[a[i]] = i;
	}
	ans.push_back(vector<int>());
	ans.back().push_back(v.size());
	for (int i = 0; i < v.size(); i++) ans.back().push_back(v[i]);
	v.clear();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		r[a[i]] = i;
	}
	for (int i = 0; i < n / 2; i++) {
		int t = n - i - 1;
		if (r[t] != i) {
			if (i) v.push_back(i);
			v.push_back(r[t] - i);
			v.push_back(n - i - r[t]);
			if (i) v.push_back(i);
			pp();
		}
		else if (i) {
			if (i) v.push_back(i);
			v.push_back(n - 2 * i);
			if (i) v.push_back(i);
			pp();
		}
		if (i) v.push_back(i);
		v.push_back(1);
		if (r[i] - i - 1 > 0) v.push_back(r[i] - i - 1);
		v.push_back(n - i - r[i]);
		if (i) v.push_back(i);
		pp();
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << '\n';
	}
	return 0;
}