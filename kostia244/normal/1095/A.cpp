#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i = 1, j;
	cin >> n;
	getchar();
	char c;
	while(n) {
		j = i;
		while(j--)
			c = getchar(), n--;
		putchar(c);
		i++;
	}
	return 0;
}