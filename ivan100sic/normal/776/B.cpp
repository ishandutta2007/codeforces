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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;

	if (n == 1) {
		cout << "1\n1";
		return 0;
	}

	if (n == 2) {
		cout << "1\n1 1";
		return 0;
	}

	vector<int> p(n+2, 1);

	cout << "2\n";

	for (long long i=2; i<=n+1; i++) {
		if (p[i]) {
			for (long long j=i*i; j<=n+1; j+=i) {
				p[j] = 0;
			}
		}
		cout << p[i]+1 << ' ';
	}
}