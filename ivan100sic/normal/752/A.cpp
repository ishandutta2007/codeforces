#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	k--;

	int r = k / (2*m);
	int d = k % (2*m) / 2;
	int l = k % 2;

	cout << r+1 << ' ' << d+1 << ' ' << (l ? 'R' : 'L');


}