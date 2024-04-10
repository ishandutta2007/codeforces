#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void yes() {
	cout << "Yes\n";
	exit(0);
}

void no() {
	cout << "No\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	map<int, int> mp;
	for (char x : s)
		mp[x]++;
	
	if (mp.size() > 4)
		no();
	if (mp.size() == 4)
		yes();
	if (mp.size() == 3) {
		if (s.size() > 3)
			yes();
		else
			no();
	}
	if (mp.size() == 2) {
		if (mp.begin()->second >= 2 && mp.rbegin()->second >= 2)
			yes();
		else
			no();
	}
	no();
}