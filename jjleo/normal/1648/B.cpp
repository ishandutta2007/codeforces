#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int t;
int n, c;
int a[maxn];
int x;

void solve(){
	scanf("%d%d", &n, &c);
	for(int i = 1;i <= c;i++) a[i] = 0;
	for(int i = 1;i <= n;i++) scanf("%d", &x), a[x] = 1;
	for(int i = 1;i <= c;i++) a[i] += a[i - 1];
	for(int i = 1;i <= c;i++) for(int j = i;j <= c;j += i){
		if(a[j / i] == a[j / i - 1] && a[i] != a[i - 1] && a[min(c, j + i - 1)] - a[j - 1]) return (void)puts("No");
	}
	puts("Yes");
}

int main(){
	scanf("%d", &t);
	while(t--) solve();
}