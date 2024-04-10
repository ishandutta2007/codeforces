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
	
	int n;
	cin >> n;
	vector<int> a(2*n);

	for (int& x : a) {
		cin >> x;
	}

	sort(a.begin(), a.end());
	if (a[n-1] == a[n]) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}