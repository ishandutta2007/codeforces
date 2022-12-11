#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 1e5 + 10;

int k, vis[N], ch[N];
char s[N];

int main() {
	scanf("%d%s", &k, s + 1);
	int n = strlen(s + 1), m = 0;
	for(int i = 1; i <= n; i ++) {
		if(!vis[s[i] - 'a']) {
			vis[s[i] - 'a'] = 1;
			m ++;
			if(m <= k) ch[i] = 1;
		}
	}
	if(m < k) puts("NO");
	else {
		puts("YES");
		for(int i = 1; i <= n; i ++) {
			if(ch[i] && i != 1) puts("");
			putchar(s[i]);
		}
	}
	return 0;
}