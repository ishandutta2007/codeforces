#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, d, m;
int ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &d, &m);
		ans = 1;
		for(long long j = 2;j <= (d << 1);j <<= 1){
			ans = 1ll * ans * ((j >> 1) + 1 - (d < j ? (j - d - 1) : 0)) % m;
		}
		printf("%d\n", (ans + m - 1) % m);
	}
}