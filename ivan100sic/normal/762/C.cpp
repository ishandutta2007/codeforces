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

int fwd[100005], bck[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string a, b;
	cin >> a >> b;

	int n = a.size();
	int m = b.size();

	a = string(" ") + a;
	b = string(" ") + b;

	int j = 0;

	fwd[0] = 0;
	for (int i=1; i<=n; i++) {
		if (a[i] == b[j+1]) {
			j++;
		}
		fwd[i] = j;
	}

	j = m+1;
	bck[n+1] = m+1;
	for (int i=n; i>=1; i--) {
		if (a[i] == b[j-1]) {
			j--;
		}
		bck[i] = j;
	}

	int mn = m+1, ml, mr;
	for (int i=0; i<=n; i++) {
		if (bck[i+1] - fwd[i] - 1 < mn) {
			mn = bck[i+1] - fwd[i] - 1;
			ml = fwd[i];
			mr = bck[i+1];
		}
	}

	if (mn == m) {
		cout << "-";
	} else if (mn <= 0) {
		cout << b;
	} else {
		/*
		cerr << ml << ' ' << mr << '\n';
		cerr << b << '\n';
		*/
		if (ml > 0) {
			cout << b.substr(1, ml);
		}
		if (mr <= m) {
			cout << b.substr(mr);
		}
	}

	

}