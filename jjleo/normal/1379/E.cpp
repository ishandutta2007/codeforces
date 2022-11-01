#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, k;
inline bool check(int n, int k){
	if(n % 2 == 0) return false;
	if(k == 0) return !(n & (n + 1));
	if(k == 1) return n & (n + 1);
	if(n == 9 && k == 2) return false;
	return k > 0 && k <= max(0, (n - 3) / 2);
} 

int cnt;

void dfs(int n, int k, int fa){
	printf("%d ", fa);
	int x = ++cnt;
	for(int i = 1;i < n - 1;i = i * 2 + 1){
		int j = n - 1 - i;
		int y = k - (max(i, j) >= min(i, j) * 2);
		if(check(j, y)){
			dfs(i, 0, x);
			dfs(j, y, x);
			return;
		}
	}
}

int main(){
	scanf("%d%d", &n, &k);
	if(!check(n, k)) return printf("No"), 0;
	puts("Yes");
	dfs(n, k, 0);
}