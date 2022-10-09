// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

map<pair<int, multiset<int>>, int> nimber;

int rek(int pre, multiset<int> s) {
	if (nimber.count({pre, s})) {
		return nimber[{pre, s}];
	}
	auto& w = nimber[{pre, s}];
	set<int> z;

	for (int x : s) {
		auto s2 = s;
		s2.erase(s2.find(x));
		int pre2 = x-1;
		if (pre) {
			s2.insert(pre);
		}

		z.insert(rek(pre2, s2));
	}

	while (z.count(w)) w++;
	return w;
}

int resi(vector<int> a) {
	return rek(0, multiset<int>(begin(a), end(a))) > 0;
}

int pamet(vector<int> a) {
	sort(begin(a), end(a));
	if (a.back() > accumulate(begin(a), end(a)-1, 0)) {
		return 1;
	} else {
		return accumulate(begin(a), end(a), 0) % 2;
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	// for (int i=1; i<=10; i++) {
	// 	for (int j=1; j<=10; j++) {
	// 		if (pamet({i, j}) != resi({i, j})) {
	// 			cerr << i << ' ' << j << '\n';
	// 			return 1;
	// 		}
	// 	}
	// }
	//
	// for (int i=1; i<=10; i++) {
	// 	for (int j=i; j<=10; j++) {
	// 		for (int k=i; k<=10; k++) {
	// 			if (pamet({i, j, k}) != resi({i, j, k})) {
	// 				cerr << i << ' ' << j << ' ' << k << '\n';
	// 				return 1;
	// 			}
	// 		}
	// 	}
	// }
	//
	// for (int i=1; i<=10; i++) {
	// 	for (int j=i; j<=10; j++) {
	// 		for (int k=i; k<=10; k++) {
	// 			for (int l=i; l<=10; l++) {
	// 				if (pamet({i, j, k, l}) != resi({i, j, k, l})) {
	// 					cerr << i << ' ' << j << ' ' << k << '\n';
	// 					return 1;
	// 				}
	// 			}
	// 		}
	// 	}
	// }

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; i++) cin >> a[i];
		cout << (pamet(a) ? "T\n" : "HL\n");
	}

}