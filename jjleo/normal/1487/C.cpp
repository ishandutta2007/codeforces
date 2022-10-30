#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = n - 1;i;i--){
			for(int j = 1;j <= i;j++){
				if(!(n & 1) && j == n / 2) printf("0 ");
				else if(j <= n / 2) printf("1 ");
				else printf("-1 ");
			}
		}
		puts("");
	}
}