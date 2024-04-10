#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;

	{
		// skini sa pocetka nule
		int x = 0;
		while (x < (int)s.size() && s[x] == '0')
			x++;
		s = s.substr(x);
	}

	// skini sa kraja nule (ako ima tacke negde)
	if (s.find('.') != string::npos) {
		while (s.size() && s.back() == '0')
			s.pop_back();
	}
		
	int pt = s.size();
	for (int i=0; i<(int)s.size(); i++)
		if (s[i] == '.')
			pt = i;
	// gde je bila tacka upamti
	if (pt != (int)s.size())
		s = s.substr(0, pt) + s.substr(pt+1);

	if (pt == 1) {
		if (s.size() > 1) {
			cout << s[0] << '.' << s.substr(1) << '\n';	
		} else {
			cout << s[0] << '\n';
		}
	} else if (pt > 1) {
		// truncuj s.substr(1);
		auto b = s.substr(1);
		while (b.size() && b.back() == '0')
			b.pop_back();
		if (b.size())
			b = string(".") + b;
		cout << s[0] << b << 'E' << pt-1 << '\n';
	} else {
		// broj je manji od 1, opet skidamo nule
		auto b = s;
		int x = 0;
		while (x < (int)b.size() && b[x] == '0') {
			x++;
		}
		b = b.substr(x);
		string c;
		if (b.size() == 1)
			c = b;
		else
			c = string(1, b[0]) + '.' + b.substr(1);
		cout << c << "E" << -x-1 << '\n';
	}
}