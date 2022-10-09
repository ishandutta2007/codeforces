#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];

string spoji_levo(int* a, int n) {
	string s(n, '(');
	for (int i=0; i<n-1; i++) {
		s += (char)(a[i] + '0');
		s += ")->";
	}
	s += (char)(a[n-1] + '0');
	s += ")";
	return s;
}

string spoji_desno(int* a, int n) {
	string s;
	for (int i=0; i<n-1; i++) {
		s += '(';
		s += (char)(a[i] + '0');
		s += "->";
	}
	s += "(";
	s += (char)(a[n-1] + '0');
	s += string(n, ')');
	return s;
}

string resi_jedna_nula(int* a, int n) {
	string s;
	if (n > 1) {
		s = spoji_levo(a, n-1);
		s = string("(") + s + "->0)";
	} else {
		s = "0";
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	int tz = 0;
	while (n-1-tz >= 0 && a[n-1-tz] == 0)
		tz++;

	string s;
	if (tz == 1) {
		s = resi_jedna_nula(a, n);
	} else if (tz >= 3) {
		if (tz == n) {
			s = spoji_desno(a, n-1);
			s = string("(") + s + "->0)";
		} else {
			s = spoji_desno(a+n-tz, tz-1);
			string p = spoji_desno(a, n-tz);
			s = "((" + p + "->" + s + ")->0)";
		}
	} else if (tz == 2) {
		// ako su sve od pocetka dotle kecevi, ne moze
		int z = -1;
		for (int i=0; i<n-tz; i++)
			if (a[i] == 0)
				z = i;
		if (z != -1) {
			string q = resi_jedna_nula(a+z+1, n-z-2);
			q = string("(0->") + q + ")";
			if (z == 0) {
				s = string("((") + q + ")->0)";
			} else {
				s = string("(((") + spoji_levo(a, z) + ")->(" + q + "))->0)";
			}
		}
	}

	if (s.size()) {
		cout << "YES\n" << s << '\n';
	} else {
		cout << "NO\n";
	}
}