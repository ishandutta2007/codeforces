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
	int t;
	cin >> t;
	map<int, int> q;
	for (int kk = 0; kk < t; kk++) {
		char c;
		cin >> c;
		string s;
		cin >> s;
		if (c == '+') {
			int chis = 0;
			for (int i = 0; i < len(s); i++) {
				chis *= 10;
				chis += (s[i] - '0') % 2;
			}
			if (q.find(chis) == q.end()) {
				q[chis] = 1;
			}
			else {
				q[chis]++;
			}
		}
		if (c == '-') {
			int chis = 0;
			for (int i = 0; i < len(s); i++) {
				chis *= 10;
				chis += (s[i] - '0') % 2;
			}
			q[chis]--;
		}
		if (c == '?') {
			int chis = 0;
			for (int i = 0; i < len(s); i++) {
				chis *= 10;
				chis += (s[i] - '0') % 2;
			}
			if (q.find(chis) == q.end()){
				cout << 0 << endl;
			}
			else{
				cout << q[chis] << endl;
			}
		}
	}
}