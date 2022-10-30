#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int a[maxn];
int ans = 1 << 30;

void dfs(int l, int r, int x, int y){
	if(!y){
		//printf("%d %d %d %d--\n", l, r, x, y);
		ans = min(ans, x);
		return;
	}
	int mid = r;
	for(int i = l;i <= r;i++){
		if(a[i] & y){
			mid = i - 1;
			break;
		}
	}
	if(mid == l - 1){
		dfs(mid + 1, r, x, y >> 1);
	}else if(mid == r){
		dfs(l, mid, x, y >> 1);
	}else{
		dfs(l, mid, x + y, y >> 1);
		dfs(mid + 1, r, x + y, y >> 1);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	dfs(1, n, 0, 1 << 29);
	printf("%d", ans);
}