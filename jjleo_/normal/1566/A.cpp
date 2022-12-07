#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, s;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &s);
		printf("%d\n", s / (n / 2 + 1));
	} 
}