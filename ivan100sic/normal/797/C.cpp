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

string s, k, t, u;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	n = s.size();

	k = s;
	for (int i=n-2; i>=0; i--) {
		k[i] = min(k[i], k[i+1]);
	}

	for (int i=0; i<n; i++) {
		while (t.size() && *t.rbegin() <= k[i]) {
			u += *t.rbegin();
			t.pop_back();
		}

		t += s[i];
	}

	while (t.size() > 0) {
		u += *t.rbegin();
		t.pop_back();
	}
	cout << u;
}