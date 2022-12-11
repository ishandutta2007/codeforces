#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;

string s[3];
int ans = 2;

bool is(string a, string b) {
	return a[0] + 1 == b[0] && a[1] == b[1];
}

bool is2(string a, string b) {
	return a[0] + 2 == b[0] && a[1] == b[1];
}


int main() {
	cin >> s[0] >> s[1] >> s[2];
	sort(s, s + 3);
	if((s[0] == s[1] && s[1] == s[2]) || (is(s[0], s[1]) && is(s[1], s[2]))) puts("0");
	else {
		if(s[0] == s[1] || s[1] == s[2] || s[0] == s[2]) ans = min(ans, 1);
		if(is(s[0], s[1]) || is(s[0], s[2]) || is(s[1], s[2])) ans = min(ans, 1);
		if(is2(s[0], s[2]) || is2(s[0], s[1]) || is2(s[1], s[2])) ans = min(ans, 1);
		cout << ans << endl;
	}
	return 0;
}