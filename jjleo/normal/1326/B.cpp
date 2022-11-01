#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n;
int a, b[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
	printf("%d ", a = b[1]);
	for(int i = 2;i <= n;i++){
		if(b[i] > 0) printf("%d ", a = b[i] + a);
		else printf("%d ", b[i] + a);
	}
}