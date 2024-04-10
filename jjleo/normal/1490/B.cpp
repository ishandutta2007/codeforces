#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[3], x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(a, 0, sizeof(a));
		for(int i = 1;i <= n;i++) scanf("%d", &x), a[x % 3]++;
		int x = 0;
		if(a[1] > a[x]) x = 1;
		if(a[2] > a[x]) x = 2;
		int ans = 0;
		for(int i = 1;i <= 100;i++){
			if(a[x] < n / 3){
				x = (x + 1) % 3;
				continue;
			}
			ans += a[x] - n / 3;
			a[(x + 1) % 3] += a[x] - n / 3;
			a[x] = n / 3;
			x = (x + 1) % 3;
		}
		printf("%d\n", ans);
	}
}