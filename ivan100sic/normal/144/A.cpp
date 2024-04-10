#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int a[105], n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	int p=1;
	for (int i=2; i<=n; i++) {
		if (a[i] > a[p]) {
			p = i;
		}
	}

	int sol = 0;

	for (int i=p-1; i>=1; i--) {
		swap(a[i], a[i+1]);
		sol++;
	}




	p=1;
	for (int i=2; i<=n; i++) {
		if (a[i] <= a[p]) {
			p = i;
		}
	}

	sol += n-p;

	cout << sol;

}