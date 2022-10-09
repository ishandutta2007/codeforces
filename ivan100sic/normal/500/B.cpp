#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[305];
string s[305];
bool v[305];
basic_string<int> w;

void dfs(int x) {
	v[x] = 1;
	w += x;
	for (int y=0; y<n; y++)
		if (!v[y] && s[x][y] == '1')
			dfs(y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> s[i];
	for (int i=0; i<n; i++) {
		if (!v[i]) {
			w = {};
			dfs(i);
			sort(w.begin(), w.end());
			basic_string<int> q;
			for (int x : w)
				q += a[x];
			sort(q.begin(), q.end());
			int j = 0;
			for (int x : w)
				a[x] = q[j++];
		}
	}
	for (int i=0; i<n; i++)
		cout << a[i] << " \n"[i == n-1];
}