#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k, x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		k = 0;
		while(n--) scanf("%d", &x), k |= x;
		puts(k ? "YES" : "NO");
	} 
}