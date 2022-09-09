#include <bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 5;
vector<int> edges[nax];
int count_subtree[nax][5];
int total_subtree[nax];
long long answer;
int n, k;

int subtract(int a, int b) {
	return ((a - b) % k + k) % k;
}

void dfs(int a, int par, int depth) {
	count_subtree[a][depth % k] = total_subtree[a] = 1;
	for(int b : edges[a])
		if(b != par) {
			dfs(b, a, depth + 1);
			for(int i = 0; i < k; ++i)
				for(int j = 0; j < k; ++j) {
					// compute distance modulo k
					int remainder = subtract(i + j, 2 * depth);
					// compute x such that (distance + x) is divisible by k
					int needs = subtract(k, remainder);
					answer += (long long) needs
							* count_subtree[a][i] * count_subtree[b][j];
				}
			for(int i = 0; i < k; ++i)
				count_subtree[a][i] += count_subtree[b][i];
			total_subtree[a] += total_subtree[b];
		}
	// in how many pairs we will count the edge from 'a' to its parent?
	answer += (long long) total_subtree[a] * (n - total_subtree[a]);
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(1, -1, 0);
	assert(answer % k == 0);
	printf("%lld\n", answer / k);
}