#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int x = 1;
		while((x << 1) <= n - 1) x <<= 1;
		for(int i = 0;i < n;i++) if((i & x) && i != x) printf("%d ", i);
		printf("%d ", x);
		for(int i = 0;i < n;i++) if(!(i & x)) printf("%d ", i);puts("");
	}
}