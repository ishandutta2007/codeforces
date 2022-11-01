#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, q;
int a[maxn], x;

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		if(!a[x]) a[x] = i;
	}
	while(q--){
		scanf("%d", &x);
		printf("%d ", a[x]);
		for(int i = 1;i <= 50;i++) if(a[i] < a[x]) a[i]++;
		a[x] = 1;
	}
}