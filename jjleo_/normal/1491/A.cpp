#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, q;
int a[maxn], x, y, sum;

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), sum += a[i];
	while(q--){
		scanf("%d%d", &x, &y);
		if(x == 1){
			if(a[y]) sum--;
			else sum++;
			a[y] ^= 1;
		}else{
			printf("%d\n", y <= sum);
		}
	}
}