#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		string a, b; cin >> a >> b;
		ans.clear();
		int s = 0, e = n - 1; bool r = false;
		for (int i = n - 1; i >= 0; i--) {
			if ((r && a[e] != b[i]) || (!r && a[e] == b[i])) {
				if (s < e) e--;
				else e++;
				continue;
			}
			if (a[s] != a[e]) 
				ans.push_back(1);
			ans.push_back(abs(s - e) + 1);
			if (s < e) s++;
			else s--;
			swap(s, e);
			r = !r;
		}	
		cout << ans.size() << " ";
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
	return 0;
}