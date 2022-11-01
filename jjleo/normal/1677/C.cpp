#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn], A[maxn], b[maxn];
bool vis[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), A[a[i]] = i;
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]), vis[i] = false;
		int sum = 0;
		for(int i = 1;i <= n;i++) if(!vis[a[i]]){
			int x = i, cnt = 0;
			while(!vis[a[x]]){
				cnt++, vis[a[x]] = true;
				x = A[b[x]];
			}
			if(cnt & 1) sum++;
		}
		long long ans = 0;
		for(int i = 1;i <= (n - sum) / 2;i++) ans -= i * 2, ans += (n - i + 1) * 2;
		printf("%lld\n", ans);
	}
}