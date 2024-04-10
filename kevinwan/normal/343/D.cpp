#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 524288
int cnt = 1;
int id[maxn],s[maxn],pid[maxn];
vector<int> g[maxn];
set<int> emp;
void dfs(int x, int p) {
	id[x] = cnt++,s[x]=1;
	for (int y : g[x])if (y != p)pid[y]=id[x],dfs(y,x), s[x] += s[y];
}
int main() {
	int n,i,a,b,qq;
	set<int>::iterator it;
	scanf("%d", &n);
	for (i = 0; i < n - 1; i++)scanf("%d%d", &a, &b), g[a].push_back(b), g[b].push_back(a);
	for (i = 1; i <= n; i++)emp.insert(i);
	dfs(1, 0);
	scanf("%d", &qq);
	while (qq--) {
		scanf("%d%d", &a, &b);
		if (a == 1) {
			cnt = 0;
			for (it = emp.lower_bound(id[b]); 1;cnt++ ) {
				if (it == emp.end())break;
				if (*it >= id[b] + s[b])break;
				emp.erase(it++);
			}
			if (cnt)emp.insert(pid[b]);
		}
		else if (a == 2) {
			emp.insert(id[b]);
		}
		else {
			if (emp.lower_bound(id[b]) == emp.lower_bound(id[b] + s[b]))printf("1\n");
			else printf("0\n");
		}
	}
	getchar(); getchar();
}