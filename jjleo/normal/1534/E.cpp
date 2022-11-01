#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, k;
queue<int> q;
bool vis[maxn];
int f[maxn], a[maxn];

int main(){
	scanf("%d%d", &n, &k);
	q.push(n), vis[n] = true;
	while(!q.empty()){
		int x = q.front();q.pop();
		for(int i = 0;i <= k;i++){
			if(i > n - x || k - i > x) continue;
			int to = x + i - (k - i);
			if(to >= 0 && to <= n && !vis[to]){
				vis[to] = true, q.push(to), f[to] = i;
			}
		}
	}
	if(!vis[0]) return printf("-1"), 0;
	int now = 0, ans = 0;
	while(now ^ n){
		printf("?");
		int cnt1 = f[now], cnt2 = k - f[now];
		//printf("%d %d--\n", now, f[now]);
		for(int i = 1;i <= n;i++){
			if(a[i] && cnt1) a[i] = 0, cnt1--, printf(" %d", i);
			else if(!a[i] && cnt2) a[i] = 1, cnt2--, printf(" %d", i);
		}
		puts(""), fflush(stdout);
		int x;scanf("%d", &x), ans ^= x;
		now -= f[now] - (k - f[now]);
	}
	printf("! %d", ans);
}