#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	string s;
	cin >> s;
	int n = s.length();
	int t1 = 0;
	int t2 = 0;
	int fl = false;
	int ind = -1;
	int ans = 0;
	string ss = "";
	for (int i = 0; i < n; i++) {
		if (s[i] == '2' and !fl) {
			fl = true;
			ind = i;
			ss += '2';
		}
		else if (s[i] == '2') {
			ss += '2';
		}
		else if (s[i] == '1' and !fl) {
			t2++;
		}
		else if (s[i] == '1') {
			ans++;
		}
		else if (s[i] == '0' and !fl) {
			t1++;
		}
		else {
			ss += '0';
		}
	}
	for (int i = 0; i < t1; i++) {
		cout << '0';
	}
	for (int i = 0; i < t2 + ans; i++) {
		cout << '1';
	}
	//cout << ind << " " << t2 + ans << endl;
	cout << ss << "\n";
	//system("pause");
	return 0;
}