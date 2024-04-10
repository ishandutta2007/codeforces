#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int x = 0;
		for(int i = 0;i <= 30;i++) if(n & (1 << i)) x = i;
		printf("%d\n", (1 << x) - 1);
	}
}