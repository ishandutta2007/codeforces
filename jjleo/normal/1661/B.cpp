#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;

int main(){
	scanf("%d", &n);
	while(n--){
		int x;
		scanf("%d", &x);
		int ans = 233;
		for(int i = 0;i <= 30;i++){
			int sum = 0;
			int y = (x + i) % 32768;
			while(y) y <<= 1, y %= 32768, sum++;
			ans = min(ans, sum + i);
		}
		printf("%d ", ans);
	}
}