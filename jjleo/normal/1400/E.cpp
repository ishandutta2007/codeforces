#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int a[maxn];

int dfs(int l, int r){
	int x = 1e9, sum = 0;
	for(int i = l;i <= r;i++) x = min(x, a[i]);
	if(x > r - l + 1) return r - l + 1;
	sum += x;
	
	int last = l;
	for(int i = l;i <= r;i++){
		a[i] -= x;
		//printf("%d %d %d--\n", i, a[i], last);
		if(!a[i]){
			if(last <= i - 1) sum += dfs(last, i - 1);
			last = i + 1;
		}
		
	}
	if(last != l && last <= r) sum += dfs(last, r);
	
	return min(sum, r - l + 1);
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	printf("%d", dfs(1, n));
}