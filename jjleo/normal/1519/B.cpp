#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &m, &k);
		puts(min(n - 1 + (m - 1) * n, m - 1 + (n - 1) * m) <= k && k <= max(n - 1 + (m - 1) * n, m - 1 + (n - 1) * m) ? "YES" : "NO");
	}
}