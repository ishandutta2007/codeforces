#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int a[maxn];
int sum;

int main(){
	scanf("%d", &n);
	int x = 1, sum = n * (n + 1) / 2;
	for(int i = 2;i <= n;i++){
		printf("? %d %d", x, i);
		puts(""), fflush(stdout);
		int j, k;
		scanf("%d", &j);
		printf("? %d %d", i, x);
		puts(""), fflush(stdout);
		scanf("%d", &k);
		if(j < k){
			a[i] = k, sum -= k;
		}else{
			a[x] = j, sum -= j, x = i;
		}
	}
	a[x] = sum;
	printf("!");
	for(int i = 1;i <= n;i++) printf(" %d", a[i]);
	puts("");
}