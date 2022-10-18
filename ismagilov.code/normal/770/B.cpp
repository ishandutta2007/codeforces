#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <bitset>

using namespace std;

string s;

int main() {	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cerr.tie(0);
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		ans += s[i] - '0';
	}
	string q;
	for (int i = int(s.size()) - 1; i >= 0; i--) {
		int p;
		if (s[i] > '0') {
			p = -1;
			for (int j = 0; j <= i; j++) {
				p += s[j] - '0';
			}
			for (int j = i + 1; j < s.size(); j++) {
				p += 9;
			}
			if (p > ans) {
				ans = p;
				q = "";
				for (int j = 0; j < i; j++) {
					q += s[j];
				}
				q += (s[i] - 1);
				for (int j = i + 1; j < s.size(); j++) {
					q += '9';
				}
			}
		}
	}
	if (q == "") {
		q = s;
	}
	reverse(q.begin(), q.end());
	while (q.back() == '0') {
		q.pop_back();
	}
	reverse(q.begin(), q.end());
	cout << q;
}