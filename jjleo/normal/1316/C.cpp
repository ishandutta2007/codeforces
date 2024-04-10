#include <bits/stdc++.h>

using namespace std;

int n, m, p;
int a, b, x;

int main(){
	scanf("%d%d%d", &n, &m, &p);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		if(a) continue;
		if(x % p) a = i;
	}
	for(int i = 1;i <= m;i++){
		scanf("%d", &x);
		if(b) continue;
		if(x % p) b = i;
	}
	printf("%d", a + b - 2);//
}