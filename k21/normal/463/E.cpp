#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

const int MAXN = 101000;

int N, Q;
int values[MAXN];

vector<int> edges[MAXN];

vector<int> children[MAXN];
int parent[MAXN];

void root(int node, int from) {
	parent[node] = from;

	for (int child : edges[node]) if (child != from) {
		children[node].push_back(child);
		root(child, node);
	}
}

int answer[MAXN];

vector<int> factorize(int n) {
	vector<int> result;
	int i = 2;
	while (n > 1) {
		if (i * i > n) {
			result.push_back(n);
			break;
		}
		if (n % i == 0) {
			result.push_back(i);
			do n /= i;
			while (n % i == 0);
		}
		++i;
	}

	return result;
}

void update(int depth, int node, map<int, pair<int, int>> &part) {
	int ans = -2;
	int adepth = -1;

	vector<int> factors = factorize(values[node]);
	map<int, pair<int, int>> backup;
	vector<int> added;

	for (int factor : factors) {
		auto it = part.find(factor);
		if (it != part.end()) {
			if (it->second.first > adepth) {
				adepth = it->second.first;
				ans = it->second.second;
			}
			backup.insert(*it);
		} else {
			added.push_back(factor);
		}
	}

	for (int factor : factors) {
		part[factor] = {depth, node};
	}

	for (int child : children[node]) {
		update(depth + 1, child, part);
	}

	for (int factor : added) {
		auto it = part.find(factor);
		part.erase(it);
	}

	for (auto &p : backup) {
		part[p.first] = p.second;
	}

	answer[node] = ans;
}

int main() {
	scanf("%d%d", &N, &Q);
	REP(i,N) scanf("%d", values + i);
	REP(i,N-1) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a; --b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	root(0, -1);
	map<int, pair<int, int>> part;
	update(0, 0, part);

	REP(qi, Q) {
		int t, v, w;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d", &v);
			--v;
			printf("%d\n", answer[v] + 1);
		} else {
			scanf("%d%d", &v, &w);
			--v;
			values[v] = w;
			update(0, 0, part);
		}
	}

	return 0;
}