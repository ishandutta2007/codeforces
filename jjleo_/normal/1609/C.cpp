#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int t, n, e;
int p[maxn], cnt;
bool tag[maxn];
int a[maxn];
int nxt[maxn];

int main(){
	tag[1] = true;
	for(int i = 2;i < maxn;i++){
		if(!tag[i]) p[++cnt] = i;
		for(int j = 1;j <= cnt && p[j] * i < maxn;j++){
			tag[p[j] * i] = true;
			if(i % p[j] == 0) break;
		}
	}
	scanf("%d", &t);
	while(t--){
		long long ans = 0;
		scanf("%d%d", &n, &e);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = n + 1;i <= n * 2 + 1;i++) a[i] = 4, nxt[i] = i + 1;
		for(int i = n;i;i--){
			if(a[i + e] != 1) nxt[i] = i + e;
			else nxt[i] = nxt[i + e];
			if(a[i] == 1){
				if(!tag[a[nxt[i]]]) ans += (nxt[nxt[i]] - nxt[i]) / e;
			}else if(!tag[a[i]]){
				ans += (nxt[i] - i) / e - 1;
			}
			//printf("%d %d %lld--\n", i, nxt[i], ans);
		}
		printf("%lld\n", ans);
	}
}