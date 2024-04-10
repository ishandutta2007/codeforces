#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin >> T;
	while (T --) {
		int n; string s;
		cin >> n >> s;
		vector <int> a(n);
		for (int i = 0; i < n; ++ i) a[i] = n - i;
		for (int i = 0; i < s.size(); ) {
			if (s[i] == '<') {
				int j = i;
				while (i < s.size() && s[i] == '<')
					++ i;
				reverse(a.begin() + j, a.begin() + i + 1);
			} else {
				++ i;
			}
		}
		for (int i = 0; i < n; ++ i) cout << a[i] << " "; cout << endl;
		vector <int> b(n);
		for (int i = 0; i < n; ++ i) b[i] = i + 1;
		for (int i = 0; i < s.size(); ) {
			if (s[i] == '>') {
				int j = i;
				while (i < s.size() && s[i] == '>')
					++ i;
				reverse(b.begin() + j, b.begin() + i + 1);
			} else {
				++ i;
			}
		}
		for (int i = 0; i < n; ++ i) cout << b[i] << " "; cout << endl;
	}
	return 0;
}