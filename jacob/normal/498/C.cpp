#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n1, n2;
vector<int> a1, a2;
vector< vector<int> > edges;
vector<char> been1, been2;
vector<int> cap1, cap2;

vector< vector<int> > active1, active2;

int countPow(int n, int t) {
	int result = 0;
	while (n % t == 0) {
		++result;
		n /= t;
	}
	return result;
}

bool dfs2(int p, int from);

bool dfs1(int p) {
	if (been1[p]) {
		return false;
	}
	been1[p] = true;
	for (auto it = edges[p].begin(); it != edges[p].end(); ++it) {
		if (dfs2(*it, p)) {
			return true;
		}
	}
	return false;
}

bool dfs2(int p, int from) {
	if (been2[p]) {
		return false;
	}
	been2[p] = true;
	if (cap2[p] != 0) {
		--cap2[p];
		active2[p].push_back(from);
		return true;
	}
	for (auto it = active2[p].begin(); it != active2[p].end(); ++it) {
		if (dfs1(*it)) {
			*it = from;
			return true;
		}
	}
	return false;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	set<int> primes;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		if (i % 2 == 0) {
			a1.push_back(t);
		} else {
			a2.push_back(t);
		}
		for (int i = 2; i * i <= t; ++i) {
			if (t % i == 0) {
				primes.insert(i);
				do {
					t /= i;
				} while (t % i == 0);
			}
		}
		if (t != 1)
			primes.insert(t);
	}
	n1 = (int) a1.size();
	n2 = (int) a2.size();
	edges.resize(n1);
	for (int i = 0; i < m; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		--v1; --v2;
		if (v1 % 2 == 1) {
			swap(v1, v2);
		}
		v1 /= 2;
		v2 /= 2;
		edges[v1].push_back(v2);
	}
	int result = 0;
	active1.assign(n1, vector<int>());
	active2.assign(n2, vector<int>());
	for (auto it = primes.begin(); it != primes.end(); ++it) {
		cap1.assign(n1, 0);
		cap2.assign(n2, 0);
		for (int i = 0; i < n1; ++i) {
			active1[i].clear();
			cap1[i] = countPow(a1[i], *it);
		}
		for (int i = 0; i < n2; ++i) {
			active2[i].clear();
			cap2[i] = countPow(a2[i], *it);
		}
		for (;;) {
			been1.assign(n1, 0);
			been2.assign(n2, 0);
			bool foundSomething = false;
			for (int i = 0; i < n1; ++i) {
				if (cap1[i] != 0 && dfs1(i)) {
					--cap1[i];
					foundSomething = true;
					break;
				}
			}
			if (foundSomething)
				++result;
			else
				break;
		}
	}
	cout << result << endl;
}