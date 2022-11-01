#include <bits/stdc++.h>
#define fo(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
#define N 1234

int n, m, a, b, ans, s[N];
vector<int> al[N];
void dfs(int at) {
	if (s[at]) return;
	s[at] = 1; ans++;
	for (int to : al[at]) dfs(to);
}
int main() {
	scanf("%d %d", &n, &m);
	fo(i,0,m) scanf("%d %d", &a, &b), al[a].push_back(b), al[b].push_back(a);
	dfs(1);
	puts(m == n-1 && ans == n ? "yes" : "no");

	return 0;
}