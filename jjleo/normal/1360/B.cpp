#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n); 
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		int ans = 100000;
		for(int i = 2;i <= n;i++) ans = min(ans, a[i] - a[i - 1]);
		printf("%d\n", ans);
	}
}