#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, a, b;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &a, &b);
		int ans = b - a;
		for(int i = 0;i <= b - a;i++){
			int sum = 0;
			for(int j = 25;~j;j--){
				if(((a + i) & (1 << j)) && !(b & (1 << j))) sum += 1 << j;
				if(!((a + i) & (1 << j)) && (b & (1 << j)) && sum - (1 << j) >= 0) sum -= 1 << j;
			}
			ans = min(ans, sum + i + 1);
		}
		printf("%d\n", ans);
	}
}