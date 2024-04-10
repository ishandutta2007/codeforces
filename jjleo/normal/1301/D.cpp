#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m, k;
int ans[maxn][2], cnt;

void solve(char c, int x){
	if(!x) return;
	if(k - x <= 0) x = k;
	ans[++cnt][0] = x, ans[cnt][1] = c;
	k -= x;
	if(!k){
		printf("%d\n", cnt);
		for(int i = 1;i <= cnt;i++) printf("%d %c\n", ans[i][0], ans[i][1]);
		exit(0);
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	if(4 * n * m - 2 * n - 2 * m < k) return printf("NO"), 0;
	puts("YES");
	for(int i = 1;i < n;i++) solve('R', m - 1), solve('L', m - 1), solve('D', 1);
	for(int i = 1;i < m;i++) solve('R', 1), solve('U', n - 1), solve('D', n - 1);
	solve('L', m - 1), solve('U', n - 1);
	/*solve(m - 1, 'R'), solve(n - 1, 'D'), solve(m - 1, 'L'), solve(n - 1, 'U');
	solve(n - 1, 'D'), solve(m - 1, 'R'), solve(n - 1, 'U'), solve(1, 'L');
	int x = m - 1, y = n - 1;
	while(x > 1 && y > 1){
		solve(n - 1, 'D'), solve(n - y, 'U'), solve(m - x, 'R'), solve(m - x, 'L'), solve(x - 1, 'L'), solve(x - 1, 'R'), solve(y - 1, 'U');
		--x, --y;
		solve(1, 'L');
	}
	if(x > 1){
		while(x > 1){
			solve(n - 1, 'D'), solve(n - 1, 'U');
			--x, slve(1, 'L');
		}
	}else if(y > 1){
		while(y > 1){
			solve(m - 1, 'R'), solve(m - 1, 'U');
			--y, slve(1, 'U');
		}
	}*/
}