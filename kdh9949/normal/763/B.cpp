#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

int main(){
	scanf("%d", &n);
	puts("YES");
	for(int i = 0; i < n; i++){
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		a %= 2; b %= 2;
		if(a < 0) a += 2;
		if(b < 0) b += 2;
		printf("%d\n", a * 2 + b + 1);
	}
	return 0;
}