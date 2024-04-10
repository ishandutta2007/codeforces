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

int a[4];
bool tri, seg;

void probaj(int a, int b, int c) {
	if (a+b > c) {
		tri = true;
	} else if (a+b == c) {
		seg = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	sort(a, a+4);

	probaj(a[0], a[1], a[2]);
	probaj(a[0], a[1], a[3]);
	probaj(a[0], a[2], a[3]);
	probaj(a[1], a[2], a[3]);

	if (tri) {
		cout << "TRIANGLE\n";
	} else if (seg) {
		cout << "SEGMENT\n";
	} else {
		cout << "IMPOSSIBLE\n";
	}
}