#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, a, b;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &a, &b);
		for(int i = 1;;i++){
			bool tag = false;
			for(int j = 0;j < i;j++){
				int x = a;
				for(int k = 1;k <= i - j;k++) x /= b + j;
				if(x == 0){
					tag = true;
					printf("%d\n", i);
					break;
				}
			}
			if(tag) break;
		}
	}
}