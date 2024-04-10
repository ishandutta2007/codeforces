#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;


int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	int t1 = 0, t2 = 0;
	int cur = 1;
	int last = a[0].first;
	vector<char> ans(n);
	vector<int> chec;
	for (int i = 1; i < n; i++) {
		//cout << a[i].first << " " << last << " ---- " << t1 << " " << t2 << "\n";
		if (a[i].first == last) {
			//cout << "one\n";
			cur++;
		}
		else {
			if (cur > 1) {
				//cout << "two\n";
				for (int j = i - cur; j < i; j++) {
					ans[a[j].second] = 'A';
				}
				if (cur > 2) {
					chec.push_back(i - 1);
				}
				cur = 1;
				last = a[i].first;
			}
			else {
				cur = 1;
				last = a[i].first;
				if (t1 > t2) {
					//cout << "three\n";
					t2++;
					ans[a[i - 1].second] = 'B';
				}
				else {
					//cout << "four\n";
					t1++;
					ans[a[i - 1].second] = 'A';
				}
			}
		}
	}
	int i = n;
	if (cur > 1) {
		for (int j = i - cur; j < i; j++) {
			ans[a[j].second] = 'A';
		}
		if (cur > 2) {
			chec.push_back(i - 1);
		}
	}
	else {
		if (t1 > t2) {
			t2++;
			ans[a[i - 1].second] = 'B';
		}
		else {
			t1++;
			ans[a[i - 1].second] = 'A';
		}
	}
	/*cout << t1 << t2 << "\n"; 
	for (int i = 0; i < n; i++) {
		cout << ans[i];
	}*/
	if (abs(t1 - t2) > chec.size()) {
		cout << "NO\n";
	}
	else {
		if (t1 != t2) {
			int ind = 0;
			char ch = '0';
			if (t1 > t2) ch = 'B';
			else ch = 'A';
			char ach = 'A';
			if (ch == 'A') ach = 'B';
			while (ind != abs(t1 - t2)) {
				if (ans[a[chec[ind]].second] == ch) {
					for (int j = chec[ind] - 1; j >= 0; j--) {
						if (a[j].first != a[j + 1].first) {
							break;
						}
						else {
							ans[a[j].second] = ach;
						}
					}
					ind++;
				}
				else {
					ans[a[chec[ind]].second] = ch;
				}
			}
		}
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			cout << ans[i];
		}
		cout << endl;
	}
	//system("pause");
	return 0;
}