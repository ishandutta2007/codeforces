#include <iostream>
#include <cstdio>
using namespace std;

int n, k, p;
char s[110];

int main() {
	scanf("%d%d%s", &n, &k, s + 1);
	p = n + 1;
	for(int i = 2; i <= n; i ++) {
		bool flag = true;
		for(int j = 1; i + j - 1 <= n; j ++) {
			if(s[j] != s[i + j - 1]) {flag = false; break;}
		}
		if(flag) {p = i; break ;}
	}
	if(p == n + 1) for(int i = 1; i <= k; i ++) printf("%s", & s[1]);
	else {
		printf("%s", &s[1]);
		for(int i = 1; i < k; i = i + 1)
			printf("%s", &s[n - p + 2]);
	}
	return 0;
}