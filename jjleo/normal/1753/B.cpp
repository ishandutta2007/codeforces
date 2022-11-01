#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

int n, x;
int a[maxn];

int main(){
	scanf("%d%d", &n, &x);
	for(int i = 1;i <= n;i++){
		int y;
		scanf("%d", &y);
		a[y]++;
	}
	for(int i = 1;i < x;i++){
		if(a[i] % (i + 1)){
			puts("No");
			return 0;
		}
		a[i + 1] += a[i] / (i + 1);
	}
	puts("Yes");
}