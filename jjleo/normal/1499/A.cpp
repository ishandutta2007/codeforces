#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, k1, k2, w, b;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d%d", &n, &k1, &k2, &w, &b);
		if((k1 + k2) / 2 * 2 < 2 * w || (2 * n - k1 - k2) / 2 * 2 < 2 * b){
			puts("NO");
			continue; 
		}
		puts("YES");
	}
}