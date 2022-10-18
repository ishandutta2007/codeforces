#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"

using namespace std;

main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int t;
	cin >> t;
	string s;
	cin >> s;
	int i = 0;
	for (i = 0; i < n && s[i] != '.'; i++) {
	}
	i++;
	int kek = i - 1;
	int lel[n];
	int kk = 0;
	for (int bb = 0; bb < n; bb++) {
		if (s[bb] != '.') {
			lel[kk] = s[bb] - '0';
			kk++;
		}
	}
	int kol = 0;
	for (; i < n; i++) {
		if (s[i] == '4') {
			kol++;
		}
		if (s[i] < '4') {
			kol = 0;
		}
		if (s[i] > '4') {
			kol = min(kol + 1, t);
			lel[i - kol - 1]++;
			for (int j = i - kol; j > 0; j--) {
				if (lel[j] > 9) {
					lel[j] = 0;
					lel[j - 1]++;
				}
			}
			if (lel[0] == 10) {
				cout << 1;
				lel[0] = 0;
			}
			int kek1 = 0;
			for (int j = i - kol; j > 0; j--) {
				if (lel[j] == 0) {
					kek1++;
				}
				else {
					break;
				}
			}
			for (int j = 0; j < i - kol - kek1; j++) {
				if (j == kek) {
					cout << '.';
				}
				cout << lel[j];
			}
			return 0;
		}
	}
	cout << s;
}