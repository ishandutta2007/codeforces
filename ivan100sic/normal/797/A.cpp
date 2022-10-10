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

int f[100005];

void sito() {
	for (int i=2; i<100005; i++) {
		if (f[i] == 0) {
			f[i] = i;
			if (i <= 30000) {
				for (int j=i*i; j<100005; j+=i) {
					if (f[j] == 0) {
						f[j] = i;
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	sito();

	int n, k;
	cin >> n >> k;
	vector<int> a;
	while (n > 1) {
		int x = f[n];
		n /= x;
		a.push_back(x);
	}
	if (a.size() < k) {
		cout << -1;
		return 0;
	}
	while (a.size() > k) {
		int x = *a.rbegin();
		a.pop_back();
		*a.rbegin() *= x;
	}
	for (int x : a) {
		cout << x << ' ';
	}
}