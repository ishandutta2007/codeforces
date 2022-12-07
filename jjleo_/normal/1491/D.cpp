#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, x, y;

bool dfs(int i, int x){
	if(i == x) return true;
	for(int j = 1;i + j <= x;j++) if((i & j) == j && dfs(i + j, x)) return true;
	return false;
}

int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%d%d", &x, &y);
		if(x > y){
			puts("NO");
			continue;
		}
		int ans = 0;
		bool tag = false;
		for(int i = 0;i < 30;i++){
			ans += ((x & (1 << i)) != 0) - ((y & (1 << i)) != 0);
			if(ans < 0){
				tag = true;
				break;
			}
		}
		puts(!tag ? "YES" : "NO");
	}
}