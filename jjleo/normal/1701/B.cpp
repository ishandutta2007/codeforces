#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
bool vis[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		puts("2");
		for(int i = 1;i <= n;i++) vis[i] = false;
		for(int i = 1;i <= n;i++) if(!vis[i]){
			int x = i;
			while(x <= n){
				vis[x] = true;
				printf("%d ", x);
				x *= 2;
			}
		}
		puts("");
	}
}