#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 5e4 + 10;

char s[N];
int n;

bool check(int l, int r, bool po = 0) {
	static bool use[30];
	fill(use, use + 26, 0);
	for(int i = l; i <= r; i ++) if(s[i] != '?') {
		if(use[s[i] - 'A']) return 0;
		use[s[i] - 'A'] = 1;
	}
	if(!po) return 1;
	int p = 0;
	for(int i = l; i <= r; i ++) {
		while(use[p]) p ++;
		if(s[i] != '?') continue ;
		s[i] = 'A' + p; use[p] = 1;
	}
	for(int i = 1; i <= n; i ++)
		if(s[i] == '?') s[i] = 'A';
	puts(s + 1); return 1;
}

int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	for(int i = 1; i <= n - 26 + 1; i ++) {
		if(check(i, i + 26 - 1)) {
			check(i, i + 26 - 1, 1);
			return 0;
		}
	}
	puts("-1");
	return 0;
}