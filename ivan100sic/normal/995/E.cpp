#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int dizi(int x, int arg, int p) {
	if (arg == 0) {
		return 1;
	}
	if (arg == 1) {
		return x % p;
	}
	auto t = dizi(x, arg >> 1, p);
	t = t*1ll*t % p;
	if (arg & 1)
		t = t*1ll*x % p;
	return t;
}

int inv(int x, int p) {
	return dizi(x, p-2, p);
}

int u, v, p;

map<int, int> p1, p2;

deque<int> bfs() {
	queue<int> q1, q2;

	p1[u] = -1;
	q1.push(u);

	p2[v] = -1;
	q2.push(v);

	int x = -1;

	while (q1.size() && q2.size()) {
		// prvi
		{
			x = q1.front(); q1.pop();
			if (p2.count(x))
				break;
			
			for (int y : {(x+1)%p, (x+p-1)%p, inv(x, p)}) {
				if (!p1.count(y)) {
					p1[y] = x;
					q1.push(y);
				}
			}
		}
		// drugi
		{
			x = q2.front(); q2.pop();
			if (p1.count(x))
				break;
			
			for (int y : {(x+1)%p, (x+p-1)%p, inv(x, p)}) {
				if (!p2.count(y)) {
					p2[y] = x;
					q2.push(y);
				}
			}
		}
	}

	deque<int> put = {x};
	
	int y = x;
	while (p1[y] != -1) {
		y = p1[y];
		put.push_front(y);
	}
	y = x;
	while (p2[y] != -1) {
		y = p2[y];
		put.push_back(y);
	}
	return put;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> u >> v >> p;

	auto put = bfs();

	cout << (int)put.size() - 1 << '\n';
	
	for (int i=1; i<(int)put.size(); i++) {
		int x = put[i-1];
		int y = put[i];

		if ((x+1)%p == y)
			cout << "1 ";
		else if ((y+1)%p == x)
			cout << "2 ";
		else
			cout << "3 ";
	}

}