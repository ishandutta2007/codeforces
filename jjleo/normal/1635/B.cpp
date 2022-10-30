#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n, a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int ans = 0;
		for(int i = 2;i < n;i++){
			if(a[i] > a[i - 1] && a[i] > a[i + 1]){
				if(i + 2 < n && a[i + 2] > a[i + 1] && a[i + 2] > a[i + 3]) a[i + 1] = max(a[i], a[i + 2]), ans++, i = i + 3;
				else a[i + 1] = a[i], ans++;
			}
		}
		printf("%d\n", ans);
		for(int i = 1;i <= n;i++) printf("%d ", a[i]);puts("");
	}
}