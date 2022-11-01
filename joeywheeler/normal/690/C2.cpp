#include <bits/stdc++.h>
#define fo(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
#define N 123456

int n, m, a, b, s[N], dst[N], ans;
vector<int> al[N];
queue<int> q;
void go(int a, int d) {
	if (s[a]) return;
	s[a] = 1; dst[a] = d;
	q.push(a);
}
void bfs(int fr) {
	go(fr, 0);
	while (!q.empty()) {
		int at = q.front(); q.pop();
		for (int to : al[at]) go(to, dst[at]+1);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	fo(i,0,m) {
		scanf("%d %d", &a, &b); a--; b--;
		al[a].push_back(b); al[b].push_back(a);
	}
	bfs(0);
	int bst = 0;
	fo(i,1,n) if (dst[i] > dst[bst]) bst = i;
	fo(i,0,n) s[i] = 0;
	bfs(bst);
	fo(i,0,n) ans = max(ans, dst[i]);
	printf("%d\n", ans);

	return 0;
}