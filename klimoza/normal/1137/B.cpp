#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>
#include <random>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;
double eps = 1e-12;

vector<int> z_function(string s) {
	int n = (int)s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i<n; ++i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	string s, t;
	cin >> s >> t;
	if (t.size() > s.size()) cout << s << endl;
	else {
		int cnt1 = 0;
		int cnt2 = 0;
		for (char i : s) cnt1 += (i == '1');
		for (char i : t) cnt2 += (i == '1');
		if (cnt1 < cnt2) {
			cout << s << endl;
		}
		else if (t.size() == s.size() && cnt1 == cnt2) {
			cout << t << endl;
		}
		else {
			vector<int> z = z_function(t);
			int maxi = 0;
			for (int i = t.size() - 1; i > 0; i--) {
				if (z[i] == t.size() - i) maxi = t.size() - i;
			}
			int ind = 0;
			int last = cnt1;
			for (int i = 0; i < s.size(); i++) {
				if (last == 0) {
					cout << '0';
					continue;
				}
				if (s.size() - i == last) {
					cout << '1';
					last--;
					continue;
				}
				if (ind == t.size()) ind = maxi;
				if (t[ind] == '1') {
					last--;
				}
				cout << t[ind];
				ind++;
			}
			cout << endl;
		}
	}
	//system("pause");
	return 0;
}