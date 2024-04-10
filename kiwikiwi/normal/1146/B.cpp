#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

string t;
int main() {
	cin >> t;
	int len = t.size();
	int l = len;
	for (int i = 0; i < len; i++)
		if (t[i] == 'a')
			l++;
	if (l % 2 != 0) {
		puts(":(");
		return 0;
	}
	l /= 2;
	string t1 = t.substr(0, l);
	string t2 = t1;
	for (int i = 0; i < l; i++)
		if (t1[i] != 'a')
			t2.push_back(t1[i]);
	if (t2 != t) {
		puts(":(");
	} else {
		cout << t1 << endl;
	}
}