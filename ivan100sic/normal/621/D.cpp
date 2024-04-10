#include <bits/stdc++.h>
using namespace std;

// govno od zadatka ok

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool blizu(ld x, ld y) {
	if (x == 0 || y == 0)
		return x == 0 && y == 0;
	if ((x < 0) != (y < 0))
		return false;
	return abs(x/y - 1) < 1e-14;
}

struct brojka {
	ld lg;
	int id;

	brojka(ld x, ld y, ld z, int id) {
		lg = pow(y, z) * log(x); // staje u extended
		this->id = id;
	}

	bool operator< (const brojka& b) const {
		if (blizu(lg, b.lg))
			return id < b.id;
		return lg > b.lg;
	}
};

string str[13] = {
	"",
	"x^y^z",
	"x^z^y",
	"(x^y)^z",
	"",
	"y^x^z",
	"y^z^x",
	"(y^x)^z",
	"",
	"z^x^y",
	"z^y^x",
	"(z^x)^y",
	"",
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ld x, y, z;
	cin >> x >> y >> z;

	vector<brojka> vb;
	vb.emplace_back(x, y, z, 1);
	vb.emplace_back(x, z, y, 2);
	vb.emplace_back(x, z*y, 1, 3);

	vb.emplace_back(y, x, z, 5);
	vb.emplace_back(y, z, x, 6);
	vb.emplace_back(y, z*x, 1, 7);

	vb.emplace_back(z, x, y, 9);
	vb.emplace_back(z, y, x, 10);
	vb.emplace_back(z, x*y, 1, 11);

	int i = min_element(vb.begin(), vb.end())->id;
	cout << str[i] << '\n';
}