#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int x = 0, y = 0, z;
		int sum = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &z);
			x = max(sum += z, x);
		}
		scanf("%d", &m);
		sum = 0;
		for(int i = 1;i <= m;i++){
			scanf("%d", &z);
			y = max(sum += z, y);
		}
		printf("%d\n", x + y);
	}
}