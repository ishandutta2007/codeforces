#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, t;
int k, x;

int main(){
	scanf("%d%d", &n, &t);
	while(t--){
		scanf("%d", &k);
		int l = 0, r = n - 1, mid;
		while(l < r){
			mid = (l + r >> 1) + 1;
			printf("? 1 %d\n", mid);
			fflush(stdout);
			scanf("%d", &x);
			if(mid - x < k) l = mid;
			else r = mid - 1;
		}
		printf("! %d\n", l + 1);
	}	
}