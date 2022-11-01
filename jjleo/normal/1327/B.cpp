#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k, x, y, z;
bool a[maxn];
int b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		y = 0;
		for(int i = 1;i <= n;i++) a[i] = false, b[i] = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &k);
			while(k--){
				scanf("%d", &x);
				if(!a[x] && !b[i]){
					a[x] = true, b[i] = x;
				}
			} 
			if(!b[i]) y = i;
		} 
		for(int i = 1;i <= n;i++) if(!a[i]) z = i;
		if(!y) puts("OPTIMAL");
		else printf("IMPROVE\n%d %d\n", y, z);
	}
}