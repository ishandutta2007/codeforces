#include <bits/stdc++.h>
using namespace std;

int n;

int main () {
	scanf("%d", &n);

	int plus = 0, minus = 0;

	for(int i = 0; i < n; i++) {
		char temp;
		scanf(" %c", &temp);
		if(temp == '+') plus++;
		if(temp == '-' and plus) plus--;
	}

	printf("%d\n", plus);

	return 0;
}