#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];

bool check(int x){
	for(int i = 2;i * i <= x;i++) if(x % i == 0) return true;
	return false;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int sum = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), sum += a[i];
		if(check(sum)){
			printf("%d\n", n);
			for(int i = 1;i <= n;i++) printf("%d ", i);puts("");
			continue;
		}
		printf("%d\n", n - 1);
		for(int i = 1;i <= n;i++) if(check(sum - a[i])){
			for(int j = 1;j <= n;j++) if(i ^ j) printf("%d ", j);
			puts("");
			break;
		}
	}
}