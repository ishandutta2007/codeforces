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
		for(int i = 0;3 * i <= n && !tag;i++){
			for(int j = 0;3 * i + 5 * j <= n && !tag;j++){
				for(int k = 0;3 * i + 5 * j + 7 * k <= n && !tag;k++){
					if(3 * i + 5 * j + 7 * k == n){
						tag = true;
						printf("%d %d %d\n", i, j, k);
					}
				}
			}
		}
		if(!tag) puts("-1");
	}
}