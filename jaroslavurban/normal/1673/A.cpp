#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

const string A = "Alice ";
const string B = "Bob ";
const int base = 'a' - 1;

void ProGamerMove() {
	string s; cin >> s;
	int n = s.size();
	if (n & 1) {
		if (s[0] > s.back()) swap(s[0], s.back());
		int sma = accumulate(s.begin() + 1, s.end(), 0) - (n - 1) * base;
		int smb = s[0] - base;
		assert(sma != smb);
		cout << (sma > smb ? A : B) << abs(sma - smb) << '\n';
	} else {
		cout << A;
		cout << accumulate(s.begin(), s.end(), 0) - n * base << '\n';
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}