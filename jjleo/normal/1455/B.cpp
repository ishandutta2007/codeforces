#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int sum = 0;
		for(int i = 1;i <= n;i++){
			sum += i;
			if(n + 1 == sum){
				printf("%d\n", i + 1);
				break;
			}
			if(n <= sum){
				printf("%d\n", i);
				break;
			}
		}
	}
}