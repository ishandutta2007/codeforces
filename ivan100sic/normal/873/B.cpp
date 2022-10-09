#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	map<int, int> delta;
	string s;
	int n, sol = 0;
	cin >> n;
	cin >> s;

	int sum = 0;
	delta[0] = -1;
	for (int i=0; i<n; i++) {
		sum += (s[i] == '1' ? 1 : -1);

		if (delta.find(sum) != delta.end()) {
			sol = max(sol, i - delta[sum]);
		}		

		if (delta.find(sum) == delta.end()) {
			delta[sum] = i;
		}
	}

	cout << sol;
}