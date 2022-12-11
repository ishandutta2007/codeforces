#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<vector<int> > f(int n, int lf, int rg)
{
	if (n == 1) {
		vector<vector<int> > ans;
		return ans;
	}
	if (n == 2) {
		vector<vector<int> > ans;
		ans.pb({lf});
		ans.pb({rg});
		return ans;
	}
	int md = (lf + rg) >> 1;
	vector<vector<int> > ans;
	vector<int> tmp;
	for (int i = md + 1; i <= rg; ++i) {
		tmp.pb(i);
	}
	ans.pb(tmp);
	tmp.clear();
	for (int i = lf; i <= md; ++i) {
		tmp.pb(i);
	}
	ans.pb(tmp);
	tmp.clear();
	vector<vector<int> > a = f(md - lf + 1, lf, md);
	vector<vector<int> > b = f(rg - md, md + 1, rg);
	while (sz(a) < sz(b)) {
		a.pb(vector<int>());
	}
	while (sz(b) < sz(a)) {
		b.pb(vector<int>());
	}
	for (int i = 0; i < sz(a); ++i) {
		ans.pb(vector<int>(sz(a[i]) + sz(b[i])));
		merge(a[i].begin(), a[i].end(), b[i].begin(), b[i].end(), ans.back().begin());
	}
	return ans;
}

const int inf = 2e9;

int main()
{

	int n;
	cin >> n;

	vector<vector<int> > ans = f(n, 1, n);

	vector<int> minn(n + 1, inf);

	for (int i = 0; i < sz(ans); ++i) {
		cout << sz(ans[i]) << '\n';
		vector<char> used(n + 1);
		for (int x : ans[i]) {
			cout << x << " ";
			used[x] = true;
		}
		cout << '\n';
		cout.flush();
		for (int j = 1; j <= n; ++j) {
			int x;
			cin >> x;
			if (!used[j]) {
				minn[j] = min(minn[j], x);
			}
		}
	}

	cout << "-1\n";
	for (int i = 1; i <= n; ++i) {
		cout << minn[i] << " ";
	}
	cout << '\n';
	cout.flush();

}