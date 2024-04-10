#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m, k;

int main(){
	scanf("%d%d", &n, &m);
	printf("%d\n", n - 1 + m - 1 + n * m - 1);
	for(int i = 1;i < n;i++) printf("U");
	for(int i = 1;i < m;i++) printf("L");
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < m;j++) printf((i & 1) ? "R" : "L");
		if(i ^ n) printf("D");
	}
}