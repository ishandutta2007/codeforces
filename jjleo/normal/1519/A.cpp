#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, a, b, d;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &a, &b, &d);
		puts((a + b - 1) / b <= d + 1 && (b + a - 1) / a <= d + 1 ? "YES" : "NO");
	}
}