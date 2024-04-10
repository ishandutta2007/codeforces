#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	int a=0, b=0, c=0;

	cin >> n;
	while (n--) {
		int x, y, z;
		cin >> x >> y >> z;
		a += x;
		b += y;
		c += z;
	}

	cout << ((a==0 && b==0 && c==0) ? "YES" : "NO");
}