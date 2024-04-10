#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
vector<int> g[200001];
int seq[200001],oc[200001];
bool vis[200001];
bool comp(const int&a, const int&b) { return oc[a] < oc[b]; }
void end() {
	printf("No");
	exit(0);
}
int main() {
	int n,i,a,b;
	scanf("%d", &n);
	for (i = 0; i < n - 1; i++)scanf("%d%d", &a, &b),g[a].push_back(b),g[b].push_back(a);
	for (i = 0; i < n; i++)scanf("%d", seq + i);
	for (i = 0; i < n; i++)oc[seq[i]] = i;
	for (i = 1; i <= n; i++)sort(g[i].begin(), g[i].end(), comp);
	int cur = 0;
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while (q.size()) {
		int x = q.front();
		if (seq[cur++] != x)end();
		q.pop();
		for (int y : g[x]) {
			if (!vis[y])q.push(y);
			vis[y] = 1;
		}
	}
	printf("Yes");
}