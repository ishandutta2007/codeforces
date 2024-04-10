#include <bits/stdc++.h>
using namespace std;

int n, k;

struct pt {
	int x, y;
	bool operator< (const pt& b) const {
		return x < b.x;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	set<pt> s;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		s.insert(pt{x, i+1});
	}
	if ((int)s.size() < k)
		return cout << "NO", 0;

	cout << "YES\n";
	auto it = s.begin();
	for (int i=0; i<k; i++) {
		cout << it->y << ' ' ;
		++it;
	}
}