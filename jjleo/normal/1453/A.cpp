#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;
int a[200];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		memset(a, 0, sizeof(a));
		int ans = 0, x;
		while(n--){
			scanf("%d", &x);
			a[x] = 1;
		}
		while(m--){
			scanf("%d", &x);
			if(a[x]) ans++;
		}
		printf("%d\n", ans);
	}
}