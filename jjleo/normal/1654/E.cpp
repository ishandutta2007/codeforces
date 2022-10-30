#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int sn = 333;
int n;
int a[maxn], ans = 1e9;
int b[maxn * sn + maxn], c[maxn];

void solve(){
	for(int i = 0;i <= sn;i++){
		for(int j = 1;j <= n;j++) ans = min(ans, n - (++b[a[j] - j * i + maxn * sn]));
		for(int j = 1;j <= n;j++) b[a[j] - j * i + maxn * sn] = 0;
	}
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;(sn + 1) * (j - i) < maxn && j <= n;j++){
			if(a[j] > a[i] && (a[j] - a[i]) % (j - i) == 0) ans = min(ans, n - (++c[(a[j] - a[i]) / (j - i)]) - 1);
		}
		for(int j = i + 1;(sn + 1) * (j - i) < maxn && j <= n;j++){
			if(a[j] > a[i] && (a[j] - a[i]) % (j - i) == 0) c[(a[j] - a[i]) / (j - i)] = 0;
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	solve();
	reverse(a + 1, a + 1 + n);
	solve();
	printf("%d", ans);
}