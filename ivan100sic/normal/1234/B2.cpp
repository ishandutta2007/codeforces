#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];

	set<int> s;
	deque<int> d;

	for (int i=0; i<n; i++) {
		int x = a[i];
		if (s.count(x)) {
			// nista
		} else {
			if ((int)d.size() < k) {
				d.push_front(x);
				s.insert(x);
			} else {
				int y = d.back();
				d.pop_back();
				s.erase(y);
				d.push_front(x);
				s.insert(x);
			}
		}
	}

	cout << d.size() << '\n';
	for (int x : d)
		cout << x << ' ';
	cout << '\n';
}