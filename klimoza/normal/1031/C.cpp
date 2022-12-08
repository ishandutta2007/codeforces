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
	int a, b;
	cin >> a >> b;
	bool fl = false;
	if (a > b) {
		swap(a, b);
		fl = true;
	}
	int cur = 0;
	int t1;
	t1 = -1;
	int ans = -1;
	while (cur <= a) {
		ans++;
		a -= cur;
		cur++;
	}
	if (a != 0) {
		t1 = cur - a;
		cur++;
	}
	vector<int> an;
	int r;
	if (fl) {
		r = ans;
		for (int i = 1; i < cur; i++) {
			if (i == t1) continue;
			an.push_back(i);
		}
	}
	else {
		cout << ans << "\n";
		for (int i = 1; i < cur; i++) {
			if (i == t1) continue;
			cout << i << " ";
		}
		cout << "\n";
	}
	ans = 0;
	if (t1 != -1) {
		b -= t1;
		ans++;
	}
	int st = cur;
	while (cur <= b) {
		ans++;
		b -= cur;
		cur++;
	}
	cout << ans << "\n";
	if(t1 != -1) cout << t1 << " ";
	for (int i = st; i < cur; i++) {
		cout << i << " ";
	}
	if (fl) {
		cout << "\n";
		cout << r << "\n";
		for (int i : an) {
			cout << i << " ";
		}
		cout << "\n";
	}
	//system("pause");
	return 0;
}