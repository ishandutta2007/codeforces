#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, d;
int p[5005], c[5005];
int k[5005], ans[5005];
bool izaso[5005];

int msize;
int mp[5005], mq[5005];
bool visited[5005];
basic_string<int> e[5005];

bool dfs(int y) {
	visited[y] = true;
	if (mq[y] == -1)
		return true;
	int x = mq[y];
	for (int yy : e[x]) {
		if (!visited[yy]) {
			bool t = dfs(yy);
			if (t) {
				mp[x] = yy;
				mq[yy] = x;
				mq[y] = -1;
				return true;
			}
		}
	}
	return false;
}

bool match_node(int x) {
	for (int y : e[x]) {
		if (!visited[y]) {
			bool t = dfs(y);
			if (t) {
				mp[x] = y;
				mq[y] = x;
				return true;
			}
		}
	}
	return false;
}

void extend() {
	while (1) {
		fill(visited, visited+5005, false);
		bool t = match_node(msize);
		if (t)
			msize++;
		else
			break;
	}
}

void dodaj(int student) {
	e[p[student]] += c[student];
	extend();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> p[i];
	for (int i=1; i<=n; i++)
		cin >> c[i];
	cin >> d;
	for (int i=1; i<=d; i++) {
		cin >> k[i];
		izaso[k[i]] = true;
	}

	for (int i=0; i<5005; i++)
		mp[i] = mq[i] = -1;

	// dodaj studentariju koja nikad nije izasla
	for (int i=1; i<=n; i++)
		if (!izaso[i])
			dodaj(i);

	for (int i=d; i>=1; i--) {
		ans[i] = msize;
		dodaj(k[i]);
	}

	for (int i=1; i<=d; i++)
		cout << ans[i] << '\n';
}