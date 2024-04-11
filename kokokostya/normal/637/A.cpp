#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector < pair < pair < int, int >, int > > a;

int main() {
	int N = 1000001;
	int n;
	cin >> n;
	a.resize(N);
	for (int i = 0; i < N; i++) {
		a[i].first.first = 0;
		a[i].first.second = 0;
		a[i].second = i;
	}
	int tm = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x].first.first++;
		a[x].first.second = -tm++;
	}
	sort(a.begin(), a.end());
	cout << a[N - 1].second;
	return 0;
}