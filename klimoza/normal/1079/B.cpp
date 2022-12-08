#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long int ll;


int main() {
	string s;
	cin >> s;
	int n = s.size();
	int len1 = 20;
	int cnt1 = n / 20;
	int len2 = n % 20;
	if (cnt1 == 0) {
		cout << 1 << " " << n << "\n" << s << "\n";
	}
	else if (n % 20 == 0) {
		cout << cnt1 << " 20" << "\n";
		for (int i = 0; i < n; i++) {
			cout << s[i];
			if ((i + 1) % 20 == 0) cout << "\n";
		}
	}
	else {
		while (len2 + cnt1 <= len1 - 1) {
			len2 += cnt1;
			len1--;
		}
		int ed = len1 - len2;
		vector<int> st;
		for (int i = 0; i < ed; i++) {
			st.push_back(20 * i);
		}
		int ind = 0;
		int nu = 0;
		int in_st = 0;
		cout << cnt1 + 1 << " " << len1 << "\n";
		while (nu < len1 * (cnt1 + 1)) {
			if (ind < st.size() && nu == st[ind]) {
				cout << "*";
				ind++;
			}
			else {
				cout << s[in_st];
				in_st++;
			}
			if ((nu + 1) % len1  == 0) {
				cout << "\n";
			}
			nu++;
		}
	}
	//system("pause");  
	return 0;
}