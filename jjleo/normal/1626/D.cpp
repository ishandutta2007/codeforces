#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
int a[maxn], x;

inline int get(int x){
	if(x == 0) return 1; 
	if(__builtin_popcount(x) == 1) return x;
	return 1 << (32 - __builtin_clz(x));
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) a[i] = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &x), a[x]++;
		for(int i = 1;i <= n;i++) a[i] += a[i - 1];
		int ans = 1e9;
		for(int x = 0;x <= 20;x++){
			int pos = 0;
			for(int i = 1;i <= n;i++){
				if(a[i] > (1 << x)) break;
				if(a[i] == (1 << x)){
					pos = i;
					break;
				}
				pos = i;
			}
			if(pos == n){
				ans = min(ans, 2 + (1 << x) - n);
				continue;
			}
			for(int i = pos + 1;i <= n;i++){
				ans = min(ans, (1 << x) + get(a[i] - a[pos]) + get(a[n] - a[i]) - n);
			}
		}
		printf("%d\n", ans);
	}
}