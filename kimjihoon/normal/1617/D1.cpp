#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int qry(int a, int b, int c)
{
	cout << "? " << a << " " << b << " " << c << endl;
	int t; cin >> t;
	return t;
}

vector<int> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int pr = qry(1, 2, 3), p0 = 0, p1 = 0;
		for (int i = 2; i <= n - 2; i++) {
			int t = qry(i, i + 1, i + 2);
			if (pr != t) {
				p0 = i - 1; p1 = i + 2;
				if (pr) swap(p0, p1);
				break;
			}
			pr = t;
		}
		ans.clear();
		ans.push_back(p0);
		for (int i = 1; i <= n; i++) {
			if (i != p0 && i != p1 && !qry(p0, p1, i))
				ans.push_back(i);
		}
		cout << "! " << ans.size() << " ";
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}