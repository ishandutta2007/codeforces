#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, s;
int a[1005], b[1005];
bool v[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++)
		cin >> b[i];

	queue<int> q;
	q.push(1);
	v[1] = 1;
	while (q.size()) {
		int x = q.front();
		q.pop();
		if (a[x]) {
			for (int y=x+1; y<=n; y++)
				if (a[y] && !v[y]) {
					q.push(y);
					v[y] = 1;
				}
		}
		if (b[x]) {
			for (int y=1; y<x; y++) {
				if (b[y] && !v[y]) {
					q.push(y);
					v[y] = 1;
				}
			}
		}
	}

	cout << (v[s] ? "YES\n" : "NO\n");

}