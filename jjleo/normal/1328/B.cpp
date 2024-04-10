#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		int b = 2;
		for(int i = 1;i <= n;i++){
			if(!b){
				printf("a");
				continue;
			}
			if(b == 1){
				if(k <= (n - i)) printf("a");
				else k -= n - i, printf("b"), b--; 
			}else{
				if(k <= 1ll * (n - i) * (n - i - 1) / 2) printf("a");
				else k -= 1ll * (n - i) * (n - i - 1) / 2, printf("b"), b--; 
			} 
		}
		puts("");
	}
}