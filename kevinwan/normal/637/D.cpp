#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200002],dp[200002],back[200002];
bool poss[200002];
vector<pair<int, int>> v;
int main() {
	int n, m, d, s,i,cur=0;
	scanf("%d%d%d%d", &n, &m, &s, &d);
	for (i = 1; i <= n; i++) scanf("%d", a + i);
	a[0] = -1;
	sort(a, a + n + 1);
	for (i = 0; i < n; i++)poss[i] = (a[i + 1] - a[i] - 2 >= s);
	for (i = 1; i <= n; i++) {
		while (cur != i&&(a[i]+1-(a[cur+1]-1)>d||!poss[cur])) cur++;
		if (cur == i) { printf("IMPOSSIBLE"); return 0; }
		back[i] = cur;
	}
	cur = n;
	a[n + 1] = m + 1;
	while (cur != 0) {
		if(a[cur + 1] - a[cur] - 2!=0)v.push_back({ 0,a[cur + 1] - a[cur] - 2 });
		if(a[cur] - a[back[cur] + 1] + 2 !=0)v.push_back({ 1,a[cur] - a[back[cur]+1] + 2 });
		cur = back[cur];
	}
	if(a[1] - a[0] - 2!=0) v.push_back({ 0,a[1] - a[0] - 2 });
	for (i = v.size() - 1; i >= 0; i--) {
		if (v[i].first == 0)printf("RUN %d\n", v[i].second);
		else printf("JUMP %d\n", v[i].second);
	}
	getchar(); getchar();
}