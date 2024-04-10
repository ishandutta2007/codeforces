#include <bits/stdc++.h>
#define maxn 186

using namespace std;

int t;
int n;
int a[maxn], x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(a, 0, sizeof(a));
		for(int i = 1;i <= n;i++) scanf("%d", &x), a[x]++;
		int ans = 0, y = 0;
		for(int i = 0;i <= 101;i++){
			if(y == 0){
				if(a[i] > 1) continue;
				if(a[i] == 1) y = 1, ans += i;
				else{
					ans += i * 2;
					break;
				}
			}else{
				if(a[i]) continue;
				ans += i;
				break;
			}
		}
		printf("%d\n", ans);
	}
}