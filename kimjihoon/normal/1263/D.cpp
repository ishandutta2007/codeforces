#include <iostream>
#include <string>
#include <vector>
using namespace std;

int ds[200009];
bool vs[26];
vector<int> v[26];

int uf(int n)
{
	if (n == ds[n]) return n;
	return ds[n] = uf(ds[n]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		ds[i] = i;
		string s; cin >> s;
		for (int j = 0; j < 26; j++) vs[j] = false;
		for (int j = 0; j < s.length(); j++) {
			int p = s[j] - 'a';
			if (vs[p]) continue;
			vs[p] = true;
			v[p].push_back(i);
		}
	}
	for (int i = 0; i < 26; i++)
		for (int j = 1; j < v[i].size(); j++) {
			int ua = uf(v[i][j - 1]), ub = uf(v[i][j]);
			if (ua != ub) ds[ub] = ua;
		}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (ds[i] == i)
			ans++;
	cout << ans << '\n';
	return 0;
}