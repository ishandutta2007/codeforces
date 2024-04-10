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
	string s;
	//cout << (int)'Z' << "\n";
	//cout << (int)'z' << "\n";
	//cout << (int)'9' << " " << (int)'0' << "\n";
	for (int i = 0; i < n; i++) {
		int t1 = 0, ti1 = -1, t2 = 0, ti2 = -1, t3 = 0, ti3 = -1;
		int ans1 = 0, ans2 = 0, ans3 = 0;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if ((int)s[j] <= (int)'9') {
				t3++;
				ans3 = 1;
				ti3 = j;
			}
			else if ((int)s[j] <= (int)'Z') {
				t2++;
				ans2 = 1;
				ti2 = j;
			}
			else {
				t1++;
				ans1 = 1;
				ti1 = j;
			}
		} 
		if (t1 > 0 && t2 > 0 && t3 > 0) {
			cout << s << "\n";
		}
		else if (ans1 + ans2 + ans3 == 2) {
			char change = '1';
			if (t1 == 0) change = 'a';
			else if (t2 == 0) change = 'A';
			else change = '1';
			int pos = 0;
			if (t1 > 1) pos = ti1;
			else if(t2 > 1) pos = ti2;
			else pos = ti3;
			for (int j = 0; j < s.length(); j++) {
				if (j == pos) {
					cout << change;
				}
				else {
					cout << s[j];
				}
			}
			cout << "\n";
		}
		else {
			char change1 = '0', change2 = '0';
			if (t1 == 0) change1 = 'a';
			if (t2 == 0) {
				if (change1 == '0') change1 = 'A';
				else change2 = 'A';
			}
			if (t3 == 0) {
				if (change1 == '0') change1 = '1';
				else change2 = '1';
			}
			for (int j = 0; j < s.length() - 2; j++) {
				cout << s[j];
			}
			cout << change1 << change2 << "\n";
		}
	}
	//system("pause");
	return 0;
}