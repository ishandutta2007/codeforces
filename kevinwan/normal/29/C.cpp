#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> g[100001];
set<int> nums;
map<int, int> comp;
pair<int, int> e[100001];
int back[100001];
int main() {
	int n,i,a,b;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d%d", &a, &b), e[i] = { a,b }, nums.insert(a), nums.insert(b);
	i = 0;
	for (int x : nums)back[i]=x,comp[x] = i++;
	for (i = 0; i < n; i++)g[comp[e[i].first]].push_back(comp[e[i].second]), g[comp[e[i].second]].push_back(comp[e[i].first]);
	int cur,las;
	for (i = 0; i <= n; i++)if (g[i].size() == 1)cur = i;
	printf("%d ", back[cur]);
	las = cur, cur = g[cur][0];
	while (g[cur].size()!=1) {
		printf("%d ", back[cur]);
		if (g[cur][0] != las)las = cur, cur = g[cur][0];
		else if (g[cur][1] != las)las = cur, cur = g[cur][1];
	}
	printf("%d", back[cur]);
}