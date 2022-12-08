#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	int q;
	cin >> q;
	vector<pair<int, int>> place(1e6, { 0, 0 });
	vector<pair<int, int>> time(1e6, { 0, 0 });
	char s;
	int t, l, r;
	l = 0;
	r = 0;
	for (int i = 0; i < q; i++) {
		cin >> s >> t;
		if (s == 'L') {
			place[t] = { -1, i };
			l++;
		}
		else if (s == 'R') {
			place[t] = { 1, i };
			r++;
		}
		else {
			int tim = place[t].second;
			int tl = 0;
			int tr = 0;
			//cout << tim << "\n";
			if (place[t].first == -1) {
				tl = l - time[tim].first;
				tr = r + time[tim].first - 1;
			}
			else {
				tl = l + time[tim].second - 1;
				tr = r - time[tim].second;
			}
			//cout << tl << " " << tr << "\n";
			cout << min(tl, tr) << "\n";
		}
		time[i] = { l, r };
	}
	//system("pause");
	return 0;
}