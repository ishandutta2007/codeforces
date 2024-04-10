#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn]; 

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int ans = 0;
		for(int i = 2;i <= n;i++){
			int x = min(a[i], a[i - 1]);
			while(x * 2 < max(a[i], a[i - 1])) x *= 2, ans++;
		}
		printf("%d\n", ans);
	}
}