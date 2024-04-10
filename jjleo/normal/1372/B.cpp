#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		bool tag = false;
		for(int i = 2;i * i <= n;i++){
			if(n % i == 0){
				printf("%d %d\n", n / i, n - n / i);
				tag = true;
				break;
			}
		}
		if(!tag){
			printf("%d %d\n", n - 1, 1);
		}
	} 
}