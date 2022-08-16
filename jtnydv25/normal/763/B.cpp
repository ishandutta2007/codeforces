#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))
int main(){
	int n, x1, y1, x2, y2, x, y;
	sd(n);
	printf("YES\n");
	for(int i = 1; i <= n; i++){
		sd(x1), sd(y1), sd(x2), sd(y2);
		x = abs(min(x1, x2)); y = abs(min(y1, y2));
		printf("%d\n", 1 + 2 * (x & 1) + (y & 1));
	}
}