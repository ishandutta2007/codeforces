#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn], ans[maxn];

void build(int l, int r, int d){
	if(l > r) return;
	int x = l;
	for(int i = l + 1;i <= r;i++) if(a[i] > a[x]) x = i;
	ans[x] = d;
	build(l, x - 1, d + 1), build(x + 1, r, d + 1);
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		build(1, n, 0);
		for(int i = 1;i <= n;i++) printf("%d ", ans[i]);
		puts("");
	}
}