#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<string> mat;

mat movl(mat a, int x) {
	rotate(a[x].begin(), a[x].begin()+1, a[x].end());
	return a;
}

mat movr(mat a, int x) {
	rotate(a[x].begin(), a[x].begin()+5, a[x].end());
	return a;
}

mat movu(mat a, int x) {
	char t = a[0][x];
	for (int i=0; i<5; i++)
		a[i][x] = a[i+1][x];
	a[5][x] = t;
	return a;
}

mat movd(mat a, int x) {
	char t = a[5][x];
	for (int i=4; i>=0; i--)
		a[i+1][x] = a[i][x];
	a[0][x] = t;
	return a;
}

mat ident() {
	return {
		"012345",
		"6789AB",
		"CDEFGH",
		"IJKLMN",
		"OPQRST",
		"UVWXYZ"
	};
}

mat run(mat a, string s) {
	for (int i=0; i<(int)s.size(); i+=2) {
		int x = s[i+1] - '1';
		if (s[i] == 'U') a = movu(a, x);
		if (s[i] == 'D') a = movd(a, x);
		if (s[i] == 'L') a = movl(a, x);
		if (s[i] == 'R') a = movr(a, x);
	}
	return a;
}

// string basicswap = "U1U1U1L1U1U1U1R1U1U1U1";
string basicswap = "D1L1U1R1D1D1L1U1R1D1D1L1U1R1D1D1L1U1R1D1D1L1U1R1D1";

string transpose(string s) {
	for (int i=0; i<(int)s.size(); i+=2) {
		if (0);
		else if (s[i] == 'U') s[i] = 'L';
		else if (s[i] == 'L') s[i] = 'U';
		else if (s[i] == 'D') s[i] = 'R';
		else if (s[i] == 'R') s[i] = 'D';
	}
	return s;
}

string shiftxy(string s, int r, int c) {
	for (int i=0; i<(int)s.size(); i+=2) {
		if (0);
		else if (s[i] == 'U') s[i+1] = (s[i+1] - '1' + c) % 6 + '1';
		else if (s[i] == 'D') s[i+1] = (s[i+1] - '1' + c) % 6 + '1';
		else if (s[i] == 'L') s[i+1] = (s[i+1] - '1' + r) % 6 + '1';
		else if (s[i] == 'R') s[i+1] = (s[i+1] - '1' + r) % 6 + '1';
	}
	return s;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	map<char, pair<int, int>> pos;
	auto a = ident();
	auto b = ident();
	for (auto& c : b)
		cin >> c;

	for (int i=0; i<6; i++)
		for (int j=0; j<6; j++)
			pos[a[i][j]] = {i, j};

	string sol;
	string tbs = transpose(basicswap);

	for (int rep=0; rep<5; rep++) {
		for (int rem=0; rem<6; rem++) {
			for (int i=rep; i<6; i++) {
				for (int j=(i == rep ? rem : 0); j<6; j++) {
					if (pos[b[i][j]].first == rep) {
						if (i == rep) {
							string mv = shiftxy(tbs, i, j);
							b = run(b, mv);
							sol += mv;
							i++;
						}

						while (j != rem) {
							string mv = shiftxy(basicswap, i, j);
							b = run(b, mv);
							sol += mv;
							j = (j+1) % 6;
						}

						while (i > rep) {
							string mv = shiftxy(tbs, i-1, j);
							b = run(b, mv);
							sol += mv;
							i--;
						}

						i = j = 6;
						break;
					}
				}
			}
		}
	}

	for (int i=0; i<6; i++) {
		for (int rep=0; rep<6; rep++) {
			for (int j=0; j<5; j++) {
				if (pos[b[i][j]].second > pos[b[i][j+1]].second) {
					string mv = shiftxy(basicswap, i, j);
					b = run(b, mv);
					sol += mv;
				}
			}
		}
	}

	cout << sol.size() / 2 << '\n';
	for (int i=0; i<(int)sol.size(); i+=2)
		cout << sol.substr(i, 2) << '\n';
}