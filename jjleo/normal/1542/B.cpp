#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, a, b;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &a, &b);
		if(a == 1){
			puts((n - 1) % b == 0 ? "Yes" : "No");
			continue;
		}
		long long x = 1;
		bool tag = false;
		while(x <= n){
			if((n - x) % b == 0){
				tag = true;
				break;
			}			
			x *= a;
		}
		puts(tag ? "Yes" : "No");
	}
}