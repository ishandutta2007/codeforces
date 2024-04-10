#include <bits/stdc++.h>
#define fs first
#define sc second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;
const int N = 105;
int n, m, test; 
char s[N][N];
vector<tuple<pii, pii, pii>> ans;
void rush(int x1, int y1, int x2, int y2, int x3, int y3) {
	ans.pb(make_tuple(pii(x1, y1), pii(x2, y2), pii(x3, y3)));
	s[x1][y1] ^= 1; s[x2][y2] ^= 1; s[x3][y3] ^= 1;
}
void solve(int n, int m) {
	if(n == 2 && m == 2) {
		int tmp[4], cur[4] = {s[1][1], s[1][2], s[2][1], s[2][2]};
		for(int i = 0; i < (1 << 4); i ++) {
			for(int j = 0; j < 4; j ++) tmp[j] = cur[j];
			int all = 0;
			for(int j = 0; j < 4; j ++) if(i >> j & 1) all ^= 1, tmp[j] ^= 1;
			for(int j = 0; j < 4; j ++) tmp[j] ^= all;
			if(!accumulate(tmp, tmp + 4, 0)) {
				for(int j = 0; j < 4; j ++) if(i >> j & 1) {
					if(j == 0) rush(1, 2, 2, 1, 2, 2);
					if(j == 1) rush(1, 1, 2, 1, 2, 2);
					if(j == 2) rush(1, 1, 1, 2, 2, 2);
					if(j == 3) rush(1, 1, 1, 2, 2, 1);
				}
				break ;
			}
		}
		return ;
	}
	if(n > 2) {
		for(int i = 1; i <= m; i ++) if(s[n][i]) {
			if(i == m) rush(n - 1, i - 1, n - 1, i, n, i); 
			else rush(n - 1, i, n - 1, i + 1, n, i);
		}
		solve(n - 1, m);
		return ;
	}
	//m > 2
	for(int i = 1; i <= n; i ++) if(s[i][m]) {
		if(i == 1) rush(i, m - 1, i + 1, m - 1, i, m); 
		else rush(i, m - 1, i - 1, m - 1, i, m);
	}
	solve(n, m - 1);
}
int main() {
	scanf("%d", &test);
	while(test --) {
		scanf("%d%d", &n, &m);
		ans.clear();
		for(int i = 1; i <= n; i ++) {
			scanf("%s", s[i] + 1);
			for(int j = 1; j <= m; j ++) {
				s[i][j] ^= '0';
			}
		}
		solve(n, m);
		printf("%d\n", (int)ans.size());
		for(int i = 0; i < (int) ans.size(); i ++) {
			printf("%d %d %d %d %d %d\n",
				get<0>(ans[i]).fs, get<0>(ans[i]).sc, 
				get<1>(ans[i]).fs, get<1>(ans[i]).sc,
				get<2>(ans[i]).fs, get<2>(ans[i]).sc
			);
		}
//		for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) if(s[i][j]) printf(">"); 
	}
	return 0;
}