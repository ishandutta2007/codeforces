#include <bits/stdc++.h>
using namespace std;

int k;

void f(int x){
	for(int i = 2; i <= k; i++) printf("%d %d\n", x + 1, x + i);
	for(int i = 1; i < k; i += 2) printf("%d %d\n", x + k + i, x + k + i + 1);
	for(int i = 2; i <= k; i++) for(int j = 1; j < k; j++) printf("%d %d\n", x + i, x + k + j);
}

int main(){
	scanf("%d", &k);
	if(~k & 1){ puts("NO"); return 0; }
	if(k == 1){ puts("YES\n2 1\n1 2"); return 0; }
	printf("YES\n%d %d\n%d %d\n", 4 * k - 2, (2 * k - 1) * k, 1, 2 * k);
	f(0);
	f(2 * k - 1);
}