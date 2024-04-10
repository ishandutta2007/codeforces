#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n == 1){
			puts("a");
			continue;
		} 
		if(n == 2){
			puts("ab");
			continue;
		} 
		if(n == 3){
			puts("abc");
			continue;
		} 
		if(n & 1){
			for(int i = 1;i <= (n - 2) / 2;i++) printf("a");
			printf("bc");
			for(int i = 1;i <= (n - 1) / 2;i++) printf("a");
			puts("");
		}else{
			for(int i = 1;i <= (n - 1) / 2;i++) printf("a");
			printf("b");
			for(int i = 1;i <= n / 2;i++) printf("a");
			puts("");
		}
	}
}