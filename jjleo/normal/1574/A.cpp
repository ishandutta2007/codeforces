#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++){
			printf("(");
			for(int j = 1;j < i;j++) printf("()");
			printf(")");
			for(int j = 1;j <= n - i;j++) printf("()");
			puts("");
		}
	}
}