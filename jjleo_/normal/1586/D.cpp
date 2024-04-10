#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int x;
int a[maxn];

int main(){
	scanf("%d", &n);
	a[n] = 1;
	for(int i = 1;i < n;i++){
		printf("? ");
		for(int j = 1;j < n;j++) printf("1 ");
		printf("%d\n", i + 1), fflush(stdout);
		scanf("%d", &x);
		if(x == 0){
			a[n] = n - i + 1;
			break;
		}
	}
	for(int i = 1;i < a[n];i++){
		printf("? ");
		for(int j = 1;j < n;j++) printf("%d ", a[n] - i + 1);
		printf("%d\n", 1), fflush(stdout);
		scanf("%d", &x);
		a[x] = i;
	}
	for(int i = a[n] + 1;i <= n;i++){
		printf("? ");
		for(int j = 1;j < n;j++) printf("1 ");
		printf("%d\n", i - a[n] + 1), fflush(stdout);
		scanf("%d", &x);
		a[x] = i;
	}
	printf("! ");
	for(int i = 1;i <= n;i++) printf("%d ", a[i]);
}