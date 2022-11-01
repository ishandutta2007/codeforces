#include <bits/stdc++.h>
#define maxn 400086

using namespace std;

const int p = 1e9 + 7;

int t, n;
int a[maxn], b[maxn], c[maxn];
bool vis[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), c[a[i]] = i;
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]), vis[i] = false;
		int ans = 1;
		for(int i = 1;i <= n;i++){
			if(vis[a[i]]) continue;
			ans = (ans + ans) % p;
			int x = i;
			while(!vis[a[x]]){
				vis[a[x]] = true;
				x = c[b[x]];
			}
		}
		printf("%d\n", ans);
	}
}