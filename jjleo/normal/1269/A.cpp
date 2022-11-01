#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;

int main(){
	scanf("%d", &n);
	if(n == 1) printf("9 8");
	else printf("%d %d", n * 3, n * 2);
}