#include <bits/stdc++.h>
#define vc vector
#define pr pair<int, int>
#define ll long long
#define pb push_back
#define fs first
#define sc second
#define mp make_pair

using namespace std;

#define int long long
main() {
	string s;
	cin >> s;
	int n = s.size();
	char a[n];
	bool prav = 0;
	int i;
	for (i = 0; i < n && s[i] == 'a'; i++) {
		a[i] = s[i];
	}
	if (i == n) {
		a[n - 1] = 'z';
	}
	else {
		for (i; i < n; i++) {
			if (prav) {
				a[i] = s[i];
			}
			else {
				if (s[i] > 'a') {
					a[i] = s[i] - 1;
				}
				else {
					prav = 1;
					a[i] = s[i];
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i];
	}
}