#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 4, k = 2;i - 1 <= n;i <<= 1, k++){
			if(n % (i - 1) == 0){
				printf("%d\n", n / (i - 1));
				break;
			}
		}
	}
}