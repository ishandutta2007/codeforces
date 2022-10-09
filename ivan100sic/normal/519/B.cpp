#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

int a[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	int x = 0;
	for (int i=0; i<n; i++) {
		int a;
		cin >> a;
		x ^= a;
	}
	int y = 0;
	for (int i=1; i<n; i++) {
		int a;
		cin >> a;
		x ^= a;
		y ^= a;
	}
	cout << x << '\n';
	for (int i=2; i<n; i++) {
		int a;
		cin >> a;
		y ^= a;
	}
	cout << y;
}