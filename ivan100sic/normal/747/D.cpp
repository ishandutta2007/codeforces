#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int a[200005], n, k, s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	vector<int> gaps;

	int winter0=0;

	winter0 = count_if(a+1, a+n+1, [](int x) { return x < 0;});

	if (winter0 == 0) {
		cout << 0;
		return 0;
	}

	int gap = -1, final_gap;
	for (int i=1; i<=n; i++) {
		if (a[i] >= 0) {
			if (gap != -1) {
				gap++;
			}
		} else {
			if (gap == -1) {
				gap = 0;
			} else if (gap > 0) {
				gaps.push_back(gap);
				gap = 0;
			}
		}
	}
	final_gap = gap;




	sort(gaps.begin(), gaps.end());


	int sol = n+ 1;

	// fill the final gap
	{
		int winter = winter0 + final_gap;
		int abridged = 0;

		for (int i=0; i<gaps.size(); i++) {
			if (winter + gaps[i] <= k) {
				abridged++;
				winter += gaps[i];
			} else {
				break;
			}
		}

		int changes = 2 * (gaps.size() - abridged) + 1;
		if (winter <= k) {
			sol = min(sol, changes);
		}
	}

	// don't fill the final gap
	{
		int winter = winter0;
		int abridged = 0;

		for (int i=0; i<gaps.size(); i++) {
			if (winter + gaps[i] <= k) {
				abridged++;
				winter += gaps[i];
			} else {
				break;
			}
		}

		int changes = 2 * (gaps.size() - abridged) + 2;
		if (winter <= k) {
			sol = min(sol, changes);
		}
		
	}

	if (sol == n+1) {
		sol = -1;
	}
	cout << sol;
}