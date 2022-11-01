#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[3], b[3], x, y;

void solve(){
	scanf("%d", &n);
	for(int i = 0;i < 3;i++) scanf("%d%d", &a[i], &b[i]);
	scanf("%d%d", &x, &y);
	for(int i = 0;i < 3;i++) if((a[i] == 1 || a[i] == n) && (b[i] == 1 || b[i] == n) && (a[(i + 1) % 3] == a[i] || b[(i + 1) % 3] == b[i]) && (a[(i + 2) % 3] == a[i] || b[(i + 2) % 3] == b[i])){
		puts(x == a[i] || y == b[i] ? "YES" : "NO");
		return;
	}
	for(int i = 0;i < 3;i++) if((a[i] - x) % 2 == 0 && (b[i] - y) % 2 == 0){
		puts("YES");
		return;
	}
	puts("NO");
}

int main(){
	scanf("%d", &t);
	while(t--) solve();
}