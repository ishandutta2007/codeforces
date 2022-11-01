#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;
int a[maxn];
int b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), b[i] = 0;
		int cnt = 0;
		for(int i = 1;i <= n;i++) if(!b[a[i]]) b[a[i]] = i, cnt++;
		int ans = cnt;
		int l = n;
		for(int i = n;i;i--){
			if(i < n && a[i] > a[i + 1]) break;
			l = min(l, b[a[i]]);
			if(b[a[i]] == i) cnt--;
			if(i == l) ans = min(ans, cnt);
		}
		printf("%d\n", ans);
	}
}