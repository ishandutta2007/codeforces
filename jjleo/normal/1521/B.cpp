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
		int x = 1;
		for(int i = 2;i <= n;i++) if(a[i] < a[x]) x = i;
		printf("%d\n", n - 1);
		for(int i = 2;x - i > 0;i += 2) printf("%d %d %d %d\n", x - i, x, a[x], a[x]);
		for(int i = 2;x + i <= n;i += 2) printf("%d %d %d %d\n", x + i, x, a[x], a[x]);
		const int p = 1e9 + 7;
		for(int i = 1;x - i > 0;i += 2) printf("%d %d %d %d\n", x - i, x, p, a[x]);
		for(int i = 1;x + i <= n;i += 2) printf("%d %d %d %d\n", x + i, x, p, a[x]);
	}
}