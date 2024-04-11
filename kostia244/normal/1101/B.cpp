#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long

string s;
int f, fc, lc = 0, l = -1, bc, st = 0;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (st == 0 && s[i] == '[')
			st++, f = i;
		if (st == 1 && s[i] == ':')
			st++, fc = i;
		else if (st > 1 && s[i] == ':')
			st++, lc = i;
		if (st > 2 && s[i] == ']') {
			bc = lc;
			l = i;
		}
	}
	if (l == -1)
		cout << -1;
	else {
		int n = 0;
		for (int i = fc; i < bc; i++) {
			if (s[i] == '|')
				n++;
		}
		cout << n + 4;
	}
}