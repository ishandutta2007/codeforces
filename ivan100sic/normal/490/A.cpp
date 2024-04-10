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
	int a[4] = {0,0,0,0};

	vector<int> b[4];

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a[x]++;
		b[x].push_back(i+1);
	}

	int c = *min_element(a+1, a+4);

	cout << c << '\n';

	while (c--) {
		cout << *b[1].rbegin() << ' ' << *b[2].rbegin() << ' ' << *b[3].rbegin() << '\n';
		b[1].pop_back();
		b[2].pop_back();
		b[3].pop_back();
	}
}