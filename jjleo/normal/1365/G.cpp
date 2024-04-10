#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int a[maxn];
ll x, ans[maxn];
int cnt;

void dfs(int x, int y, int z){
	if(y == 6){
		a[++cnt] = x;
		return;
	}
	if(!z) return;
	dfs(x, y, z >> 1);
	dfs(x + z, y + 1, z >> 1);
}

int n;

int main(){
	scanf("%d", &n);
	dfs(0, 0, 1 << 12);
	for(int i = 1 << 12;i;i >>= 1){
		int c = 0;
		for(int j = 1;j <= n;j++){
			if(a[j] & i) c++;
		}
		if(!c) continue;
		printf("? %d", c);
		for(int j = 1;j <= n;j++) if(a[j] & i) printf(" %d", j);
		puts(""), fflush(stdout);
		scanf("%lld", &x);
		for(int j = 1;j <= n;j++) if(!(a[j] & i)) ans[j] |= x;
	}
	printf("!");
	for(int i = 1;i <= n;i++) printf(" %lld", ans[i]);
	
}