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

	set<int> a[2];

	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		a[x % 2].insert(i);
	}

	cout << (a[0].size() == 1 ? *a[0].begin() :*a[1].begin());


}