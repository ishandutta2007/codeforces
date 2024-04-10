#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, x, y;

inline long long cal(int x, int y){
	return 1ll * (x + y) * (y - x + 1) / 2;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &x, &y);
		long long ans = 0;
		for(int i = 2, j;i <= y + 1 && i <= x;i = j + 1){
			j = min(y + 1, x / (x / i));
			int val = x / i;
			if(val >= j - 2) ans += cal(i - 2, j - 2);
			else if(val <= i - 2) ans += 1ll * val * (j - i + 1); 
			else ans += cal(i - 2, val) + 1ll * (j - 2 - val) * val;
		}
		printf("%lld\n", ans);
	}
}