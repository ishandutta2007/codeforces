#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn];
int mn[maxn], mx[maxn], N;
int x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i += 2){
			if(i + 1 > n) i--;
			printf("? 1 %d %d %d\n", i, i + 1, n - 1), fflush(stdout);
			scanf("%d", &x);
			if(x == n) N = i + 1;
			if(x == n - 1){
				printf("? 1 %d %d %d\n", i + 1, i, n - 1), fflush(stdout);
				scanf("%d", &x);
				if(x == n) N = i;
			}
			mx[i] = x;
			printf("? 2 %d %d %d\n", i, i + 1, 1), fflush(stdout);
			scanf("%d", &x);
			if(x == 2){
				printf("? 2 %d %d %d\n", i + 1, i, 1), fflush(stdout);
				scanf("%d", &x);
			}
			mn[i] = x;
			if(mx[i] == n) a[i == N ? i + 1 : i] = mn[i];
		}
		a[N] = n;
		for(int i = 1;i <= n;i += 2){
			if(i + 1 > n) i--;
			if(mx[i] == n) continue;
			printf("? 2 %d %d %d\n", i, N, 1), fflush(stdout);
			scanf("%d", &x);
			if(x == mn[i]) a[i] = mn[i], a[i + 1] = mx[i];
			else a[i] = mx[i], a[i + 1] = mn[i];
		}
		printf("!");for(int i = 1;i <= n;i++) printf(" %d", a[i]);puts("");fflush(stdout);
	}
}