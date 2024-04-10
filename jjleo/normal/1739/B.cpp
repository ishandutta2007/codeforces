#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, d[maxn];

void solve(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &d[i]);
	int x = 0;
	for(int i = 1;i <= n;i++){
		if(d[i] == 0) continue;
		if(x >= d[i]){
			puts("-1");
			return;
		}
		x += d[i];
	}
	x = 0;
	for(int i = 1;i <= n;i++) printf("%d ", x += d[i]);puts("");
}

int main(){
	scanf("%d", &t);
	while(t--) solve();
}