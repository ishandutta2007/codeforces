#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back

int n, s;
vector<int> a;

int main() {
	cin >> n;
	a.resize(n);
	for(auto&i : a)
	cin >> i;

	for(int i = 0; i < (1 << n); i++) {
		s = 0;
		for(int j = 0; j < n; j++) {
			if((i>>j)&1)
				s -= a[j];
			else
				s += a[j];
		}
		if((s%360) == 0) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";
	return 0;
}