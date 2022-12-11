#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	int k, s = 1, i, p, c[501];
	scanf("%d", &k);
	for(i=1; c[i-1] <= 1e5; i ++) c[i] = i*(i-1)/2;
	p = lower_bound(c+1, c+i, k) - c;
	char nc = 'a';
	for(int j=p; j>=1; j--) {
		while(k >= c[j]) {
			k -= c[j];
			for(int t=1; t<=j; t++) putchar(nc);
			nc ++;
			if(!k) break;
		}
	}
	return 0;
}
/*
n(n-1)/2
 
*/