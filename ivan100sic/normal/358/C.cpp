// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

string used[3] = {"pushStack", "pushQueue", "pushBack"};
string desu[3] = {"popStack", "popQueue", "popBack"};
vector<int> nums;

void gotovo(bool skip = false) {
	int n = nums.size();
	vector<bool> hi(n, false);

	vector<pair<int, int>> v(n);
	for (int i=0; i<n; i++)
		v[i] = {nums[i], i};

	sort(begin(v), end(v), greater<pair<int, int>>());

	int k = min(3, n);
	for (int i=0; i<k; i++)
		hi[v[i].second] = true;

	for (int i=0, j=0; i<n; i++) {
		if (hi[i]) {
			cout << used[j++] << '\n';
		} else {
			cout << "pushFront\n";
		}
	}

	if (!skip) {
		cout << k;
		for (int i=0; i<k; i++)
			cout << ' ' << desu[i];
		cout << '\n';
	}

	nums = {};
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		if (x == 0) {
			gotovo();
		} else {
			nums.push_back(x);
		}
	}

	gotovo(true);
}