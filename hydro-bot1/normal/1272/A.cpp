// Hydro submission #634a479a5baa0d16770c6020@1665853439924
#include <bits/stdc++.h>

using namespace std;

int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		printf("%d\n", max(0, abs(a-b)+abs(a-c)+abs(b-c)-4));
	} 
	return 0;
}