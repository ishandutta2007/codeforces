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

int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	if (n > 100) {
		cout << "YES";
		return 0;
	}

	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	sort(a, a+n);

	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			for (int k=j+1; k<n; k++) {
				if (a[i] + a[j] > a[k]) {
					cout << "YES";
					return 0;
				}
			}
		}
	}

	cout << "NO";
}