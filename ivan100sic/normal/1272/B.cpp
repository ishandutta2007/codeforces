#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<char, int> mp = {
	{'L', 0},
	{'U', 1},
	{'R', 2},
	{'D', 3}
};

bool cmp(char x, char y) {
	return mp[x] < mp[y];
}

bool lr(string s) {
	for (char x : s)
		if (x == 'U' || x == 'D')
			return false;
	return true;
}

bool ud(string s) {
	for (char x : s)
		if (x == 'L' || x == 'R')
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		int x=0, y=0;
		for (char c : s) {
			if (c == 'L')
				x--;
			else if (c == 'R')
				x++;
			else if (c == 'U')
				y++;
			else
				y--;
		}

		string t;
		for (char c : s) {
			if (x > 0 && c == 'R')
				x--;
			else if (x < 0 && c == 'L')
				x++;
			else if (y > 0 && c == 'U')
				y--;
			else if (y < 0 && c == 'D')
				y++;
			else
				t += c;
		}

		if (t.size()) {
			sort(t.begin(), t.end(), cmp);
			if (t[0] == t.back())
				t = string(1, t[0]);
			else if (lr(t))
				t = "LR";
			else if (ud(t))
				t = "UD";
		}
			

		cout << t.size() << '\n';
		cout << t << '\n';
	}	
}