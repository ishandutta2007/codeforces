#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string random_pluses(string s) {
	string p;
	for (char x : s) {
		p += x;
		if (rand() %  11) {
			p += '+';
		}
	}
	if (*p.rbegin() == '+') {
		p.pop_back();
	}
	return p;
}

long long eval(string s) {
	long long tot = 0, br = 0;
	for (char x : s) {
		if (x == '+') {
			tot += br;
			br = 0;
		} else {
			br = 10*br + x - 48;
		}
	}
	return tot + br;
}

vector<string> generisi_sve(string s) {
	int l = s.size();
	vector<string> v;
	for (int mask=0; mask < (1 << (l-1)); mask++) {
		string p;
		for (int i=0; i<l; i++) {
			p += s[i];
			if (mask & (1<<i)) {
				p += '+';
			}
		}
		v.push_back(move(p));
	}
	return v;
}

vector<string> solve_string(string s, int depth = 3) {
	if (depth == 3) {
		// pucaj random dok ne proradi
		while (1) {
			string p = random_pluses(s);
			string q = to_string(eval(p));
			auto v = solve_string(q, 2);
			if (v.size()) {
				v.push_back(p);
				return v;
			}
		}
	} else if (depth == 2) {
		if (s.size() > 10) {
			return {};
		}
		// generisi sve maske
		vector<string> sve = generisi_sve(s);
		for (string p : sve) {
			string q = to_string(eval(p));
			// cerr << s << ' ' << p << ' ' << q << '\n';
			auto v = solve_string(q, 1);
			if (v.size()) {
				v.push_back(p);
				return v;
			}
		}
	} else if (depth == 1) {
		// generisi sve maske
		vector<string> sve = generisi_sve(s);
		for (string p : sve) {
			string q = to_string(eval(p));
			// cerr << s << ' ' << p << ' ' << q << '\n';
			auto v = solve_string(q, 0);
			if (v.size()) {
				v.push_back(p);
				return v;
			}
		}
	} else if (depth == 0) {
		if (s.size() == 1) {
			return vector<string>(1, s);
		}
	}
	return {};
}

int main() {

	int n;
	string s;
	cin >> n >> s;

	auto v = solve_string(s);
	for (int i=3; i>0; i--) {
		cout << v[i] << '\n';
	}
}