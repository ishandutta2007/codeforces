#include <bits/stdc++.h>
using namespace std;

int n, k;

int main(){
	scanf("%d%d", &n, &k);
	int i;
	for(i = 1; i <= n && k + 5 * i <= 240; k += 5 * i, i++);
	printf("%d", i - 1);
	return 0;
}