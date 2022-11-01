#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;
int sum, x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		sum = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &x), sum += x;
		printf("%d\n", min(m, sum));
	}
}