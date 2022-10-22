#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	if (n > 36)printf("-1");
	else if (n == 0)printf("1");
	else {
		for (int i = 0; i < n/2; i ++)printf("8");
		if (n % 2)printf("9");
	}
	getchar(); getchar();
}