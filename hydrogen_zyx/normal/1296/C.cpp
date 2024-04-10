#include<iostream>
#include<map>
using namespace std;
int a[200005];
int dir[][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			if (c == 'L') a[i] = 2;
			else if (c == 'R') a[i] = 0;
			else if (c == 'U') a[i] = 1;
			else if (c == 'D') a[i] = 3;
		}
		map<pair<int, int>, int> m;
		int x = 0, y = 0;
		int mmin = 1000000000, ms, me;
		m.insert(pair<pair<int, int>, int>({ x,y }, 0));
		for (int i = 0; i < n; i++) {
			x += dir[a[i]][0];
			y += dir[a[i]][1];
			if (m.count({ x,y })) {
				int d = i + 1 - m[{x, y}];
				if (d < mmin) {
					mmin = d;
					ms = m[{x, y}]+1;
					me = i + 1;
				}
				m[{x, y}] = i + 1;
			}
			else {
				m.insert(pair<pair<int, int>, int>({ x,y }, i+1));
			}
		}
		if (mmin == 1000000000) cout << -1 << endl;
		else cout << ms << ' ' << me << endl;
	}
}