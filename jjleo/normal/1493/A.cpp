#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, k;
bool vis[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++) vis[i] = false;
		for(int i = k + 1;i <= n;i++) vis[i] = true;
		for(int i = k - 1;!vis[k - i] && i;i--) vis[i] = true;
		int ans = 0;
		for(int i = 1;i <= n;i++) ans += vis[i];
		printf("%d\n", ans);
		for(int i = 1;i <= n;i++) if(vis[i]) printf("%d ", i);
		puts("");
	}
}