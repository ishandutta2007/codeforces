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

	set<int> a;
	int n = 4;

	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		a.insert(x);
	}

	cout << (4 - a.size());


}