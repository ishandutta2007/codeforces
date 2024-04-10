#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, x;

int main(){
	scanf("%d", &n);
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		if(x & 1){
			cnt++;
			if(cnt & 1){
				if(x > 0) printf("%d\n", x / 2);
				else printf("%d\n", x / 2 - 1);
			}else{
				if(x > 0) printf("%d\n", x / 2 + 1);
				else printf("%d\n", x / 2);
			}
		}else{
			printf("%d\n", x / 2);
		}
	}
}