#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m, k;
int a[maxn];
bool vis[maxn];

bool solve(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1;i <= k;i++) scanf("%d", &a[i]), a[i] = k - a[i] + 1, vis[i] = false;
	int cnt = 0, x = 0;
	for(int i = 1;i <= k;i++){
//		if(i == k) return true;
		cnt++;
		if(cnt == n * m - 2) return false;
		vis[a[i]] = true;
		while(vis[x + 1]) cnt--, x++;
	}
	return true;
}

int main(){
	scanf("%d", &t);
	while(t--) puts(solve() ? "YA" : "TIDAK");
}