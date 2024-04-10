// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, r;
int q[300005];
int d[100005][3];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<3*n; i++) {
		int x;
		cin >> x;
		q[x] = i;
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<3; j++) {
			cin >> d[i][j];
		}
	}

	cin >> r;

	int k = -1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<3; j++) {
			if (d[i][j] == r) {
				k = i;
			}
		}
	}

	vector<int> pre, tu, posle;

	for (int i=0; i<k; i++) {
		pre.insert(pre.end(), d[i]+0, d[i]+3);
	}

	int sr = 0;
	{
		int u[2], v=0;
		for (int j=0; j<3; j++) {
			if (d[k][j] != r) {
				u[v++] = d[k][j];
			}
		}
		sort(u, u+2);
		tu.assign(u, u+2);

		if (q[r] > q[u[0]] || q[r] > q[u[1]])
			sr = 1;
	}

	for (int i=k+1; i<n; i++) {
		posle.insert(posle.end(), d[i]+0, d[i]+3);
	}

	sort(begin(pre), end(pre));
	sort(begin(posle), end(posle));

	posle.insert(posle.begin(), begin(tu), end(tu));

	size_t i = 0, j = 0, o = 0;
	while (i < pre.size() || j < posle.size()) {
		int f = j == posle.size() || (i < pre.size() && pre[i] < posle[j]);
		q[o++] = (f ? pre[i++] : posle[j++]);
	}

	if (sr) {
		sort(q, q+o);
	}

	for (int i=0; i<o; i++)
		cout << q[i] << " \n"[i == o-1];
}