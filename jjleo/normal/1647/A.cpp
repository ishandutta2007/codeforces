#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n % 3 == 1){
			for(int i = 1;n;i++){
				if(i & 1) printf("1"), n--;
				else printf("2"), n -= 2;
			}
		}else{
			for(int i = 0;n;i++){
				if(i & 1) printf("1"), n--;
				else printf("2"), n -= 2;
			}
		}
		puts("");
	}
}