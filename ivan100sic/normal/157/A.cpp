#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int n;
int r[333], c[333];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int z = 0, n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			r[i] += x;
			c[j] += x;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (r[i] < c[j])
				z++;
		}
	}

	cout << z << '\n';
}