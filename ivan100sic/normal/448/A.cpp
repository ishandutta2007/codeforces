#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, x, a1, a2, a3, b1, b2, b3;
	cin >> a1 >> a2 >> a3;
	cin >> b1 >> b2 >> b3;
	cin >> n;
	int a = a1+a2+a3;
	int b = b1+b2+b3;

	x = (a+4)/5 + (b+9)/10;
	if (x <= n) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}