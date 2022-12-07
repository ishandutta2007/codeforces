#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, u, v;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &u, &v);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		bool tag = false;
		for(int i = 2;i <= n;i++){
			if(abs(a[i] - a[i - 1]) > 1){
				tag = true;
				break;
			}
		}
		if(tag){
			puts("0");
			continue;
		}
		for(int i = 2;i <= n;i++) if(a[i] ^ a[i - 1]) tag = true;
		if(!tag){
			printf("%d\n", min(u + v, 2 * v));
			continue;
		}
		printf("%d\n", min(u, v));
	}
}