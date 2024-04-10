#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m, x;
int cnt[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 0;i < m;i++) cnt[i] = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			for(int j = 0;j < m;j++) cnt[j] += (x & (1 << j)) != 0;
		}
		int ans = 0;
		for(int i = 0;i < m;i++) if(cnt[i] > n - cnt[i]) ans += 1 << i;
		printf("%d\n", ans);
	}
}