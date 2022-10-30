#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 0;i < n;i++) printf("%c", 'a' + (i % 3));
		puts(""); 
	}
}