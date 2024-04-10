#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

bool isp(string& s) {
	return s.size() == 1 || (s.size() == 2 && s[0] == s[1]) || (s.size() == 3 && s[0] == s[2]);
}

void ProGamerMove() {
	int n;
	cin >> n;
	vector<string> s(n);
	multiset<string> done, notdone;
	int found = 0;
	for (auto& v : s) {
		cin >> v;
		if (isp(v)) found = true;
		notdone.insert(v);
	}
	for (auto st : s) {
		if (found) break;
		notdone.erase(st);
		auto xd = st;
		reverse(xd.begin(), xd.end());
		if (done.find(xd) != done.end()) found = true;
		if (st.size() == 3) {
			if (notdone.find(string(1, st[1]) + string(1, st[0])) != notdone.end()) found = true;
			if (done.find(string(1, st[2]) + string(1, st[1])) != done.end()) found = true;
		}
		if (found) break;
		done.insert(st);
	}
	if (found) cout << "YES\n";
	else cout << "NO\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}