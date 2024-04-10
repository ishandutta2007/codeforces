#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const unsigned mod = 998244353;
const ull mod2 = (ull)mod*mod*16;

const int H = 62;

unsigned c2[H][H];
unsigned c3[H][H][H];

int ord(char x) {
	if (islower(x))
		return x-'a';
	if (isupper(x))
		return x-'A' + 26;
	return x-'0' + 52;
}

unsigned solve_len(vector<string>& vs) {
	for (string& s : vs) {
		string p = s;
		reverse(p.begin(), p.end());
		s = min(p, s);
	}
	sort(vs.begin(), vs.end());
	vs.resize(unique(vs.begin(), vs.end()) - vs.begin());
	memset(c2, 0, sizeof(c2));
	memset(c3, 0, sizeof(c3));
	for (const string& s : vs) {
		string p = s;
		reverse(p.begin(), p.end());
		if (p == s) {
			c2[ord(p[0])][ord(p[0])] += 1;
		} else {
			c2[ord(p[0])][ord(s[0])] += 1;
			c2[ord(s[0])][ord(p[0])] += 1;
		}
	}

	for (int i=0; i<H; i++) {
		for (int j=0; j<H; j++) {
			for (int k=0; k<H; k++) {
				ull val = 0;
				for (int l=0; l<H; l++) {
					val += (ull)c2[i][l] * c2[j][l] % mod * c2[k][l];
					if (val >= mod2)
						val -= mod2;
				}
				c3[i][j][k] = val % mod;
			}
		}
	}

	ull sol = 0;
	for (int i=0; i<H; i++)
		for (int j=0; j<H; j++) {
			for (int k=0; k<H; k++) {
				for (int l=k; l<H; l++) {
					ull t1 = (ull)c3[i][j][k] * c3[i][j][l] % mod;
					ull t2 = (ull)c3[i][k][l] * c3[j][k][l] % mod;

					sol += t1 * t2 * (l == k ? 1 : 2);
					if (sol >= mod2)
						sol -= mod2;
				}
			}
		}
	return sol % mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<string>> vs(11);
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		vs[s.size()].push_back(s);
	}

	ull sol = 0;

	for (int l=3; l<=10; l++)
		sol += solve_len(vs[l]);
	
	cout << sol % mod << '\n';
}