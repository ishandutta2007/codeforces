#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, x, y;
int sum;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &x);
		sum = 0;
		bool tag = false, has = false;
		for(int i = 1;i <= n;i++){
			scanf("%d", &y);
			tag |= x != y;
			sum += y;
			has |= x == y;
		}
		if(!tag){
			puts("0");
			continue;
		}
		if(sum == n * x || has) puts("1");
		else puts("2");
	}
}