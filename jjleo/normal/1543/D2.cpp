#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k, x;

int get(int x, bool tag){
	int y = x - 1, z = 0, sum = 1;
	while(x || y){
		if(tag) z += sum * ((y % k + k - x % k) % k);
		else z += sum * ((x % k + k - y % k) % k);
		x /= k, y /= k;
		sum *= k;
	}
	return z;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k), fflush(stdout);
		for(int i = 0;i < n;i++){
			printf("%d\n", i ? get(i, i & 1) : 0), fflush(stdout);
			scanf("%d", &x);
			if(x) break;
		}
	}
}