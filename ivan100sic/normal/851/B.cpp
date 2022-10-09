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

long long ax, ay, bx, by, cx, cy, d, a, b, c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> ax >> ay >> bx >> by >> cx >> cy;
	d = ax*by + bx*cy + cx*ay - ay*bx - by*cx - cy*ax;

	auto sq = [](long long x) {
		return x*x;
	};

	a = sq(bx-cx) + sq(by-cy);
	c = sq(ax-bx) + sq(ay-by);

	if (d && a == c) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

	
}