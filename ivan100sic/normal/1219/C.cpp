#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int k;
	cin >> k;
	string s;
	cin >> s;
	if (s.size() % k) {
		string t(k, '0');
		t[0] = '1';
		for (int i=0; i<(int)s.size()/k+1; i++)
			cout << t;
		cout << '\n';
	} else {
		string t = s.substr(0, k);
		string w;
		for (int i=0; i<(int)s.size()/k; i++)
			w += t;
		if (w > s) {
			cout << w << '\n';
		} else {
			w = "";
			int j = t.size()-1;
			while (j >= 0) {
				if (t[j] == '9') {
					t[j] = '0';
					j--;
				} else {
					t[j]++;
					break;
				}
			}
			if (j == -1) {
				string t(k, '0');
				t[0] = '1';
				for (int i=0; i<(int)s.size()/k+1; i++)
					cout << t;
				cout << '\n';
			} else {
				string w;
				for (int i=0; i<(int)s.size()/k; i++)
					w += t;
				cout << w << '\n';
			}
		}
	}
}