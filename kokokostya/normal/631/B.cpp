#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	vector< pair<int, int> > arr1(n);
	vector< pair<int, int> > arr2(m);
	for (int i = 1; i <= k; i++) {
		int h, c, a;
		cin >> h >> c >> a;
		if(h == 1){
			arr1[c - 1].first = a;
			arr1[c - 1].second = i;
		}
		else {
			arr2[c - 1].first = a;
			arr2[c - 1].second = i;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr1[i].second > arr2[j].second) {
				cout << arr1[i].first << ' ';
			}
			else {
				cout << arr2[j].first << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}