#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int N = 5e4 + 10;

int n, m, c1[N], c2[N];
vector<int> c[N];

int main() {
	static char tmp[N];
	int q; scanf("%d", &q);
	while(q --) {
		scanf("%d%d", &n, &m);
		fill(c1, c1 + n, 0);
		fill(c2, c2 + m, 0);
		for(int i = 0; i < n; i ++) {
			c[i].clear();
			scanf("%s", tmp);
			for(int j = 0; j < m; j ++) {
				if(tmp[j] == '*') {
					c[i].pb(1); c1[i] ++; c2[j] ++;
				} else {
					c[i].pb(0);
				}
			}
		}
		int ans = n * m;
		for(int i = 0; i < n; i ++) {
			for(int j = 0; j < m; j ++) {
				int num = n + m - 1, res = c1[i] + c2[j];
				if(c[i][j]) res --;
				ans = min(ans, num - res);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}