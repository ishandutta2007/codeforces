#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;

int main(){
	scanf("%d", &n);
	printf("%d\n", 4 + 3 * n);
	printf("%d %d\n", 0, 0);
	printf("%d %d\n", 0, 1);
	printf("%d %d\n", 1, 0);
	printf("%d %d\n", 1, 1);
	for(int i = 1;i <= n;i++){
		printf("%d %d\n", i, i + 1);
		printf("%d %d\n", i + 1, i);
		printf("%d %d\n", i + 1, i + 1);
	}
}