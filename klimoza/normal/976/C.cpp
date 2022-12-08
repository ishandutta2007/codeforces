#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>


using namespace std;

bool comp(pair<pair<long long int, long long int>, long long int> x, pair<pair<long long int, long long int>, long long int> y) {
	if (x.first.first < y.first.first) return true;
	else if (x.first.first > y.first.first) return false;
	if (x.first.second > y.first.second) return true;
	return false;
}

int main() {
	long long int n;
	cin >> n;
	vector<pair<pair<long long int, long long int>, long long int>> segs(n);
	for (long long int i = 0; i < n; i++) {
		cin >> segs[i].first.first >> segs[i].first.second;
		segs[i].second = i;
	}
	cout << endl;
	sort(segs.begin(), segs.end(), comp);
	long long int maxich = segs[0].first.second;
	long long int ind = segs[0].second;
	bool fl = false;
	for (int i = 1; i < n; i++) {
		if (segs[i].first.second <= maxich) {
			fl = true;
			cout << segs[i].second + 1 << " " << ind + 1;
			break;
		}
		else {
			maxich = segs[i].first.second;
			ind = segs[i].second;
		}
	}
	if (!fl) cout << -1 << " " << -1;
	//system("pause");
	return 0;
}