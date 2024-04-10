#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

queue<int> rd() {
	int n;
	cin >> n;
	queue<int> q;
	while (n--) {
		int x;
		cin >> x;
		q.push(x);
	}
	return q;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	auto p = rd();
	auto q = rd();

	int moves = 0;
	while (p.size() && q.size() && moves < 40'000'000) {
		int x = p.front(); p.pop();
		int y = q.front(); q.pop();
		if (x > y) {
			p.push(y);
			p.push(x);
		} else {
			q.push(x);
			q.push(y);
		}
		moves++;
	}

	if (moves == 40'000'000)
		cout << "-1\n";
	else if (p.size())
		cout << moves << " 1\n";
	else
		cout << moves << " 2\n";
}