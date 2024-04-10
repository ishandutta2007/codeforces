#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int x, y;
int ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		y = -1e9, ans = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			if(x >= y) y = x;
			else{
				int z = y - x;
				int cnt = 0;
				while(z){
					++cnt;
					z >>= 1;
				}
				ans = max(ans, cnt);
			}
		}
		printf("%d\n", ans);
	}
}