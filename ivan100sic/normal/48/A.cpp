#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

string q[3] = {"rock", "scissors", "paper"};

int idx(string s) {
	return find(q, q+3, s) - q;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string a, b, c;
	cin >> a >> b >> c;
	if (set<string>({a, b, c}).size() == 2) {
		map<string, int> mp;
		for (string d : {a, b, c})
			mp[d]++;
		string u, v;
		if (mp.begin()->second == 1) {
			u = mp.begin()->first;
			v = mp.rbegin()->first;
		}
		else {
			v = mp.begin()->first;
			u = mp.rbegin()->first;
		}

		if ((idx(u) - idx(v) + 3) % 3 == 2) {
			if (u == a)
				cout << "F\n";
			else if (u == b)
				cout << "M\n";
			else
				cout << "S\n";
			return 0;
		}
	}

	cout << "?\n";
}