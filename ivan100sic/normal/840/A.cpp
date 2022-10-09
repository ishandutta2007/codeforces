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

int n;
vector<pair<int, int>> b;
int a[200005];

int o[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	b.resize(n);
	for (int i=0; i<n; i++) {
		cin >> b[i].first;
		b[i].second = i;
	}

	sort(b.begin(), b.end());
	sort(a, a+n);
	reverse(a, a+n);

	for (int i=0; i<n; i++) {
		int j = b[i].second;
		o[j] = a[i];
	}

	for (int i=0; i<n; i++) {
		cout << o[i] << ' ';
	}
}