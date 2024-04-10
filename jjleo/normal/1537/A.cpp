#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int sum, x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		sum = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			sum += x;
		}
		if(sum == n){
			puts("0");
			continue;
		}
		if(sum < n){
			puts("1");
			continue;
		}
		printf("%d\n", sum - n);
	}
}