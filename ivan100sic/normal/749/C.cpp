#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
	/*
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	*/
	
	int n;
	string s;
	cin >> n >> s;

	set<int> d, r, a;

	for (int i=0; i<s.size(); i++) {
		if (s[i] == 'D') {
			d.insert(i);
		} else {
			r.insert(i);
		}
		a.insert(i);
	}

	auto it = a.begin();

	while (d.size() > 0 && r.size() > 0) {
		if (d.count(*it)) {
			auto f = r.upper_bound(*it);
			if (f == r.end()) {
				f = r.begin();
			}
			r.erase(*f);
			a.erase(*f);
		} else {
			auto f = d.upper_bound(*it);
			if (f == d.end()) {
				f = d.begin();
			}
			d.erase(*f);
			a.erase(*f);
		}
		++it;
		if (it == a.end()) {
			it = a.begin();
		}
	}

	if (d.size()) {
		cout << 'D';
	} else {
		cout << 'R';
	}

}