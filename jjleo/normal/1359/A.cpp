#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &m, &k);
		int x = min(n / k, m);
		m -= x;
		printf("%d\n", x - (m / (k - 1) + (m % (k - 1) != 0)));
	}
}