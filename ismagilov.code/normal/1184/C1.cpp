#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>

#define x first
#define y second

using namespace std;
typedef long long ll;


int main() {
	/*#ifndef ONLINE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif*/
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	n = 4 * n + 1;
	vector<pair<int, int>> pt(n);
	for (int i = 0; i < n; i++) 
		cin >> pt[i].x >> pt[i].y;
	for (int i = 0; i < n; i++) {
		int minx = 1e9, miny = 1e9, maxy = -1e9, maxx = -1e9;
		for (int j = 0; j < n; j++) {
			if(i == j) 
				continue;
			minx = min(minx, pt[j].x);
			miny = min(miny, pt[j].y);
			maxx = max(maxx, pt[j].x);
			maxy = max(maxy, pt[j].y);
		}
		bool flag = 0;
		for (int j = 0; j < n; j++) {
			if(i == j) 
				continue;
			if(pt[j].x != minx && pt[j].x != maxx && pt[j].y != maxy && pt[j].y != miny) {
				flag = 1;
			}
		}
		if(flag) 
			continue;
		if(maxx - minx == maxy - miny) {
			cout << pt[i].x << " " << pt[i].y << endl;
			return 0;
		}
	}
}