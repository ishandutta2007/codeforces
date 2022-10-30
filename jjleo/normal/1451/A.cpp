#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n == 1) puts("0");
		else if(n == 2) puts("1");
		else if(n == 3) puts("2");
		else if(n & 1) puts("3");
		else puts("2");
	}
}