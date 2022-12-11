#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N], base[32];
void insert(int x) {
	for(int i = 30; ~ i; i --) {
		if(x >> i & 1) {
			if(!base[i]) {
				base[i] = x; return ;
			}
			x ^= base[i];
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
		a[i] ^= a[i - 1];
		insert(a[i]);
	}
	if(a[n] == 0) {
		puts("-1"); return 0;
	}
	int c = 0;
	for(int i = 0; i < 31; i ++) c += base[i] > 0;
	printf("%d\n", c);
	return 0;
}