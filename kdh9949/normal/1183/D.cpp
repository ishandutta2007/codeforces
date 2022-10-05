#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int c[N];

int main(){
	int q;
	scanf("%d", &q);
	while(q--){
		int n;
		scanf("%d", &n);
		fill(c+1, c+n+1, 0);
		for(int i = 0, x; i < n; i++){
			scanf("%d", &x);
			c[x]++;
		}
		sort(c+1, c+n+1);
		reverse(c+1, c+n+1);
		int r = 0;
		for(int i = 1, j = n+1; i <= n; i++){
			if(j && j <= c[i]) j--;
			j = min(j, c[i]);
			r += j;
		}
		printf("%d\n", r);
	}
}