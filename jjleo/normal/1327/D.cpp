#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n;
int p[maxn], c[maxn], a[maxn], len;
bool vis[maxn];
int ans;

void solve(int k){
	for(int i = 0;i < k;i++){
		if(ans <= k) return;
		int cnt = len / k, j = i, col = c[a[i]];
		while(cnt--){
			if(c[a[j]] ^ col) break;
			j += k;
			if(j >= len) j -= len;
			if(!cnt) ans = min(ans, k); 
		} 
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		ans = n;
		for(int i = 1;i <= n;i++) scanf("%d", &p[i]);
		for(int i = 1;i <= n;i++) scanf("%d", &c[i]);
		for(int i = 1;i <= n;i++){
			if(!vis[i]){
				len = 0;
				int j = i;
				while(!vis[j]) vis[j] = true, a[len++] = j, j = p[j];
				for(int k = 1;k * k <= len;k++){//debug:len-1 
					if(len % k) continue;
					solve(k);
					if(k * k != len) solve(len / k);
				}
			}
		}
		printf("%d\n", ans);
		for(int i = 1;i <= n;i++) vis[i] = false; 
	}
}