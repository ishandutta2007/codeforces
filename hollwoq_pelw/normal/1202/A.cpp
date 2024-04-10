#include <bits/stdc++.h>
using namespace std;
int main() {
	int q;
	cin >> q;
	while(q--) {
		string s, t;
		cin >> s >> t;
		reverse(s.begin(), s.end());
		reverse(t.begin(), t.end());
		int n = 0;
		while(t[n] != '1') n++;
		int m = n;
		while(s[m] != '1') m++;
		cout << m-n << endl;
	}
}