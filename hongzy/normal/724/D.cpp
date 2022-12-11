#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
//Dense Subsequence
int m, n, cnt;
char s[100010], ans[100010], max_char;
bool ch[100010];

int main() {
	scanf("%d\n", &m);
	gets(s+1);
	n = strlen(s+1);
	int lp = 0;
	for( ; lp <= n-m; ) {
		int min_id = 'z' + 1, pos = 0;
		for(int i=lp+1; i<=lp+m; i++)
			if(min_id >= s[i]) min_id = s[pos = i];
		ans[++ cnt] = (char)min_id;
		ch[lp = pos] = true;
		max_char = max(max_char, (char)min_id);
	}
	for(int i=1; i<=n; i++)
		if(!ch[i] && max_char > s[i]) ans[++ cnt] = s[i];
	sort(ans+1, ans+cnt+1);
	for(int i=1; i<=cnt; i++) printf("%c", ans[i]);
	printf("\n");
	return 0;
}