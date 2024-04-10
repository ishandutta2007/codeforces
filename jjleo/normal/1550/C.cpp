#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
int a[maxn];

inline bool check(int i, int j, int k){
	return !(a[i] <= a[j] && a[j] <= a[k] || a[k] <= a[j] && a[j] <= a[i]);
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		if(n == 1){
			puts("1");
			continue;
		}
		int ans = 2 * n - 1;
		for(int i = 1;i + 2 <= n;i++){
			ans += check(i, i + 1,i + 2);
		}
		for(int i = 1;i + 3 <= n;i++){
			ans += check(i, i + 1,i + 2) && check(i, i + 1, i + 3) && check(i, i + 2, i + 3) && check(i + 1, i + 2, i + 3);
		}
		printf("%d\n", ans);
	}
}