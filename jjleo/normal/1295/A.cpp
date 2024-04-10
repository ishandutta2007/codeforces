#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n & 1) n -= 3, printf("7");
		while(n) n -= 2, printf("1");
		puts("");
	}
}