#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int rate(string s) {
	int x = 0;
	for (char y : s) {
		x += y - '0';
	}
	return x;
}

string algo(string s) {

	string c;

	if (s[0] == '1') {
		c = string(s.size()-1, '9');
	} else {
		c = string(1, s[0]-1);
		c += string(s.size()-1, '9');
	}

	if (rate(c) > rate(s)) {
		return c;
	} else {
		return s;
	}
}

string brut(string s) {
	int x = stoi(s.c_str());
	
	int best=-1, bx=0;

	for (int i=1; i<=x; i++) {
		string c = to_string(i);
		if (rate(c) >= best) {
			best = rate(c);
			bx = i;
		}
	}

	return to_string(bx);
}

string dobar(string s) {

	string sol = s;

	for (int i=0; i<s.size(); i++) {
		// smanji ito slovo a ostala postavi na 9
		if (s[i] != '0') {
			string q = s;
			q[i]--;
			for (int j=i+1; j<q.size(); j++) {
				q[j] = '9';
			}

			if (rate(q) > rate(sol) || (rate(q) == rate(sol) && q > sol)) {
				sol = q;
			}
		}
	}

	while (sol[0] == '0') {
		sol.erase(0, 1);
	}

	return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;

	cout << dobar(s) << '\n';
	// cerr << brut(s) << '\n';

	return 0;

	for (int i=1; i<=10000; i++) {
		if (dobar(to_string(i)) != brut(to_string(i))) {
			cerr << i << '\n';
		}
	}
	
}