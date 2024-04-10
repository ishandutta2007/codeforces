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
int c[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int pr = qry(1, 2, 3), p0 = 0, p1 = 0;
		c[1] = pr;
		bool f = false;
		for (int i = 4; i <= n; i += 3) {
			int t = qry(i, i + 1, i + 2);
			if (!f && pr != t) {
				if (qry(i - 2, i - 1, i) != pr) {
					p0 = i - 3; p1 = i;
				}
				else if (qry(i - 1, i, i + 1) != pr) {
					p0 = i - 2; p1 = i + 1;
				}
				else {
					p0 = i - 1; p1 = i + 2;
				}
				if (pr) swap(p0, p1);
				f = true;
			}
			pr = t;
			c[i] = t;
		}
		ans.clear();
		ans.push_back(p0);
		for (int i = 1; i <= n; i += 3) {
			if (i == p0 || i + 1 == p0 || i + 2 == p0 || i == p1 || i + 1 == p1 || i + 2 == p1) {
				for (int j = i; j <= i + 2; j++)
					if (j != p0 && j != p1 && !qry(p0, p1, j))
						ans.push_back(j);
			}
			else {
				if (!c[i]) {
					int t = qry(i, i + 1, p1);
					if (!t) {
						ans.push_back(i);
						ans.push_back(i + 1);
						if (!qry(p0, p1, i + 2))
							ans.push_back(i + 2);
					}
					else {
						ans.push_back(i + 2);
						if (!qry(p0, p1, i))
							ans.push_back(i);
						else
							ans.push_back(i + 1);
					}
				}
				else {
					int t = qry(i, i + 1, p0);
					if (t) {
						if (!qry(p0, p1, i + 2))
							ans.push_back(i + 2);
					}
					else {
						if (!qry(p0, p1, i))
							ans.push_back(i);
						else
							ans.push_back(i + 1);
					}
				}
			}
		}
		cout << "! " << ans.size() << " ";
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}