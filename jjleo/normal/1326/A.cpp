#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n == 1){
			puts("-1");
			continue;
		} 
		for(int i = 1;i <= n - 2;i++) printf("2");
		if((n - 1) * 2 % 3) puts("23");
		else puts("43");
	}
}