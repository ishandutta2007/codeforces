// C.cpp : Defines the entry point for the console application.
//

#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;
int n, m;

vector<vi> edges;
vi been;
vi result;
vi parity;

void dfs(int p) {
	been[p] = true;
	parity[p] = 1 - parity[p];
	result.push_back(p);
	for (auto it = edges[p].begin(); it != edges[p].end(); ++it) {
		if (been[*it])
			continue;
		dfs(*it);
		result.push_back(p);
		if (parity[*it]) {
			result.push_back(*it);
			result.push_back(p);
			parity[*it] = 1 - parity[*it];
		} else {
			parity[p] = 1 - parity[p];
		}
	}
}

int main(void) {
	scanf("%d%d", &n, &m);
	edges.resize(n);
	been.resize(n);
	parity.resize(n);
	for (int i = 0; i < m; ++i ) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &parity[i]);
	}
	for (int i = 0; i < n; ++i) {
		if (parity[i]) {
			dfs(i);
			if (parity[i]) {
				result.erase(result.begin());
				parity[i] = 1 - parity[i];
			}
			break;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (parity[i]) {
			printf("-1");
			return 0;
		}
	}
	printf("%d\n", result.size());
	for (int i = 0; i < (int)result.size(); ++i) {
		printf("%d ", result[i]+1);
	}
	printf("\n");
}