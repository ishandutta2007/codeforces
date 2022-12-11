#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

const int N = 2e5 + 10;

int n, m, k, ne[N], a[N][6], res[6];
multiset<int> S[6];

void psh(int x) {
	for(int i = 1; i <= m; i ++) {
		S[i].insert(a[x][i]);
	}
}
void pp(int x) {
	for(int i = 1; i <= m; i ++) {
		S[i].erase(S[i].find(a[x][i]));
	}
}
int cost() {
	int ans = 0;
	for(int i = 1; i <= m; i ++) {
		ans += * -- S[i].end();
	}
	return ans;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			scanf("%d", &a[i][j]);
			ne[i] += a[i][j];
		}
	}
	int ans = 0;
	for(int i = 1, j = 0; i <= n; i ++) {
		if(ne[i] > k) {
			j = i; continue ;
		}
		while(j < n) {
			psh(++ j);
			if(cost() > k) {
				pp(j --); break ;
			}
		}
		if(j - i + 1 > ans) {
			ans = j - i + 1;
			for(int k = 1; k <= m; k ++) {
				res[k] = * -- S[k].end();
			}
		}
		pp(i);
	}
	for(int i = 1; i <= m; i ++)
		printf("%d ", res[i]);
	return 0;
}