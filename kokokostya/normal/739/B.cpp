#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair<long long, long long> > p;
vector< vector< pair<long long, long long> > > g;
vector<long long> res;
vector< vector< pair<long long, long long> > > up;
vector<long long> a;

void getup(long long v) {
	up[0][v] = p[v];
	for (long long i = 1; i < 25; i++) {
		long long to = up[i - 1][v].first;
		if (to != -1 && up[i - 1][to].first != -1) {
			up[i][v].first = up[i - 1][to].first;
			up[i][v].second = up[i - 1][v].second + up[i - 1][to].second;
		}
	}
	for (pair<long long, long long> i : g[v])
		getup(i.first);
	return;
}

void dosome(long long v) {
	long long now = v;
	long long sum = 0;
	for (long long i = 24; i >= 0; i--) {
		if (up[i][now].first != -1) {
			if (up[i][now].second + sum <= a[v]) {
				sum += up[i][now].second;
				now = up[i][now].first;
			}
		}
	}
	if(v)
		res[p[v].first]++;
	if (p[now].first != -1)
		res[p[now].first]--;
	return;
}

void dfs(long long v) {
	for (pair<long long, long long> i : g[v]) {
		dfs(i.first);
		res[v] += res[i.first];
	}
	return;
}

int main() {
	long long n;
	cin >> n;
	p.resize(n);
	g.resize(n);
	a.resize(n);
	up.resize(25, vector< pair<long long, long long> >(n, {-1, -1}));
	p[0] = { -1, -1 };
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (long long i = 1; i < n; i++) {
		long long pr, w;
		cin >> pr >> w;
		pr--;
		p[i] = { pr, w };
		g[pr].push_back({ i, w });
	}
	res.resize(n);
	getup(0);
	for (long long i = 0; i < n; i++) {
		dosome(i);
	}
	dfs(0);
	for (int i = 0; i < n; i++)
		cout << res[i] << ' ';
	return 0;
}