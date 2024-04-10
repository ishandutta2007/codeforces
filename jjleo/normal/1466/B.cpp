#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

int t;
int n;
int a[maxn], x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &x), a[x]++;
		int ans = 0;
		int x = 0;
		for(int i = 1;i <= 2 * n + 1;i++){
			if(a[i] + x > 1 && a[i]) a[i]--, a[i + 1]++;
			a[i] += x;
			if(a[i]) ans++;
		}
		printf("%d\n", ans);
		for(int i = 1;i <= 2 * n + 1;i++) a[i] = 0;
	}
}