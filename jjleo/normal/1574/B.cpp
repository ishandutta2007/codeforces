#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, a, b, c, m;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &a, &b, &c, &m);
		if(max(0, a - 1) + max(0, b - 1) + max(0, c - 1) < m){
			puts("NO");
			continue; 
		}
		if(m < max(0, max({a, b, c}) - (a + b + c - max({a, b, c})) - 1)){
			puts("NO");
			continue;
		}
		puts("YES");
	}
}