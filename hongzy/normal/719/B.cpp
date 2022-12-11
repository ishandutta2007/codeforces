#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
 
int n, c1, c2, ans1, ans2;
char s[100010], t[2] = {'r', 'b'};

int main() {
	scanf("%d\n", &n);
	gets(s+1);
	for(int i=1; i<=n; i++) {
		if(i & 1) {if(s[i] != t[i&1]) c1 ++;}
		else {if(s[i] != t[i&1]) c2 ++;}
	}
	ans1 = min(c1, c2) + abs(c1 - c2);
	c1 = c2 = 0;
	for(int i=1; i<=n; i++) {
		if(i & 1) {if(s[i] != t[(i-1)&1]) c1 ++;}
		else {if(s[i] != t[(i-1)&1]) c2 ++;}
	}
	ans2 = min(c1, c2) + abs(c1 - c2);
	printf("%d\n", min(ans1, ans2));
	return 0;
}