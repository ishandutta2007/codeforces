#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m;
int to[maxn];
int col[maxn];
int cnt;
int x, y;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) to[i] = 0, col[i] = 0;
		int ans = 0;
		for(int i = 1;i <= m;i++){
			scanf("%d%d", &x, &y);
			if(x == y) continue;
			ans++;
			to[x] = y;
		}
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			if(col[i]) continue;
			int x = i;
			++cnt;
			while(1){
				col[x] = cnt;
				x = to[x];
				if(!x) break;
				if(col[x] == cnt){
					ans++;
					break;
				}
				if(col[x] && col[x] != cnt) break;
			}
		}
		printf("%d\n", ans);
	}
}