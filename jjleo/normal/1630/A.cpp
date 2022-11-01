#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		if(k < n - 1){
			for(int i = 0;i < n / 2;i++){
				if(i == 0) printf("%d %d\n", 0, (n - 1) ^ k);
				else if(i == min(k, (n - 1) ^ k)) printf("%d %d\n", k, n - 1);
				else printf("%d %d\n", i, (n - 1) ^ i); 
			}
		}else{
			if(n == 4){
				puts("-1");
				continue;
			}
			for(int i = 0;i < n / 2;i++){
				if(i == 1) printf("%d %d\n", 1, 0);
				else if(i == 0) printf("%d %d\n", n - 2, n - 1);
				else if(i == n / 2 - 1) printf("%d %d\n", n / 2 - 1, n / 2 + 1);
				else if(i == n / 2 - 2) printf("%d %d\n", n / 2 - 2, n / 2);
				else printf("%d %d\n", i, (n - 1) ^ i); 
			}
		} 
	}
}