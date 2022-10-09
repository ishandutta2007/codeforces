#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct solver {
	string s, p;
	int free4;
	set<int> manje, vece;
	int n;

	void promeni(int i, char x) {
		if (p[i] < s[i])
			manje.erase(i);
		else if (p[i] > s[i])
			vece.erase(i);
		p[i] = x;
		if (p[i] < s[i])
			manje.insert(i);
		else if (p[i] > s[i])
			vece.insert(i);
	}

	bool ok() { // da li je p >= s
		if (manje.size() == 0)
			return true;
		if (vece.size() == 0)
			return false;
		return *manje.begin() > *vece.begin();
	}

	void init(string _s) {
		s = _s;
		n = s.size();
	}

	string solve() {
		if (n % 2)
			return string(n/2+1, '4') + string(n/2+1, '7');

		p = string(n/2, '7') + string(n/2, '4');
		if (p < s)
			return string(n/2+1, '4') + string(n/2+1, '7');

		free4 = n/2;
		for (int i=0; i<n; i++)
			if (p[i] < s[i])
				manje.insert(i);
			else if (p[i] > s[i])
				vece.insert(i);

		for (int i=0; i<n; i++) {
			if (p[i] == '4')
				break;
			if (free4 >= n)
				break;
			// probaj
			promeni(i, '4');
			promeni(free4, '7');
			if (ok()) {
				// ostavi ovako
				free4++;
			} else {
				promeni(i, '7');
				promeni(free4, '4');
			}
		}
		return p;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	solver sol;
	sol.init(s);
	cout << sol.solve() << '\n';
}