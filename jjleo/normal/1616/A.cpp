#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn], x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0;i <= 100;i++) a[i] = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &x), a[abs(x)]++;
		int ans = 0;
		for(int i = 0;i <= 100;i++){
			if(a[i]) ans++;
			if(i && a[i] > 1) ans++;
		}
		printf("%d\n", ans);
	}
}