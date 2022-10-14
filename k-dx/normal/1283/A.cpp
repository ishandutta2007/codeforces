#include <bits/stdc++.h>
using namespace std;

int main () {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int h, m;
		scanf("%d %d", &h, &m);
		
		printf("%d\n", 60 - m + (23 - h)*60);
	}

	return 0;
}