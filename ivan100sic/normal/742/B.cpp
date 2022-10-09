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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, x;
	map<int, int> a;
	long long sol = 0;

	cin >> n >> x;
	while (n--) {
		int b;
		cin >> b;
		sol += a[b ^ x];
		a[b]++;
	}
	cout << sol;
}