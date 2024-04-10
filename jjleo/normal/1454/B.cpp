#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n, x;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) a[i] = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			if(a[x]) a[x] = n + 1;
			else a[x] = i;
		} 
		x = n + 1;
		for(int i = 1;i <= n;i++){
			if(a[i] && a[i] != n + 1){
				x = a[i];
				break;
			}
		}
		if(x == n + 1) puts("-1");
		else printf("%d\n", x);
	}
}