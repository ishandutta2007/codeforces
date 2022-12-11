#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;

char s[N];
int n, st[N], top, p;

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; i ++) {
		if(top && s[st[top]] == s[i]) top --, p ++;
		else st[++ top] = i;
	}
	puts(p & 1 ? "Yes" : "No");
	return 0;
}