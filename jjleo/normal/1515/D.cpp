#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n, l, r, x;
int c[maxn][2];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &l, &r);
		for(int i = 1;i <= n;i++) c[i][0] = c[i][1] = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			c[x][i <= l]++;
			if(c[x][0] && c[x][1]) c[x][0]--, c[x][1]--;
		}
		int ans = 0;
		l = r = 0;
		for(int i = 1;i <= n;i++) l += c[i][0], r += c[i][1];
		ans += min(l, r);
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			cnt += c[i][l < r] / 2;
		}
		cnt = min(cnt, abs(l - r) / 2);
		ans += abs(l - r) - cnt;
		printf("%d\n", ans);
	}
}