#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[100009], pr[100009];
bool vs[100009], rm[100009];
vector<pair<int, int> > ans;
vector<int> st;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 2) st.push_back(i);
		if (a[i] == 1 && !st.empty()) {
			pr[st.back()] = i;
			rm[i] = true;
			st.pop_back();
		}
	}
	if (!st.empty()) {
		cout << -1 << '\n';
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] > 0 && !st.empty() && !rm[i]) {
			pr[st.back()] = i;
			st.pop_back();
		}
		if (a[i] == 3) st.push_back(i);
	}
	if (!st.empty()) {
		cout << -1 << '\n';
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] > 0 && !vs[i]) 
			ans.push_back(make_pair(i, i));
		if (a[i] == 2) {
			ans.push_back(make_pair(pr[i], i));
			vs[pr[i]] = true;
		}
		if (a[i] > 2) {
			ans.push_back(make_pair(pr[i], i));
			ans.push_back(make_pair(pr[i], pr[i]));
			vs[pr[i]] = true;
		}
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].second << " " << ans[i].first << '\n';
	return 0;
}