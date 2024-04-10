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

vector<int> a;
vector<int> l;
vector<int> r;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	a.resize(n);
	l.resize(n+1, n+1);
	r.resize(n+1, n+1);
	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			l[i] = 0;
		} else {
			if (i > 0) {
				l[i] = l[i-1] + 1;
			}
		}
	}

	for (int i=n-1; i>=0; i--) {
		if (a[i] == 0) {
			r[i] = 0;
		} else {
			if (i < n-1) {
				r[i] = r[i+1] + 1;
			}
		}
	}

	for (int i=0; i<n; i++) {
		cout << min(l[i], r[i]) << ' ';
	}


}