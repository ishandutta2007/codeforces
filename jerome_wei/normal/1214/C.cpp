#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
 
using namespace std;
 
int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool can = false;
	int bal = 0;
	int minp = 0;
	for (char c : s) {
		if (c == '(') {
			bal++;
			minp = min(minp, bal);
			if (minp == -1) {
				can = true;
			}
		} else {
			bal--;
			if (bal < 0) can = false;
			minp = min(minp, bal);
		}
	}
	if (bal == 0 && minp == 0) {
		cout << "Yes\n";
		return 0;
	}
	if (bal != 0) {
		cout << "No\n";
		return 0;
	}
	if (can) {
		cout << "Yes\n";
		return 0;
	}
	bal = 0, minp = 0, can = false;
	reverse(s.begin(), s.end());
	for (char c : s) {
		if (c == ')') {
			bal++;
			minp = min(minp, bal);
			if (minp == -1) {
				can = true;
			}
		} else {
			bal--;
			if (bal < 0) can = false;
			minp = min(minp, bal);
		}
	}
	if (can) {
		cout << "Yes\n";
		return 0;
	}
	cout << "No\n";
	return 0;
}