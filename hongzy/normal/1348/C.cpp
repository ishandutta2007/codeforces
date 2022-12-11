#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int N = 1e5 + 10;
int n, k, cnt[27];
char s[N];
int main() {
	int t; scanf("%d", &t);
	while(t --) {
		scanf("%d%d%s", &n, &k, s + 1);
		sort(s + 1, s + n + 1);
		fill(cnt, cnt + 27, 0);
		for(int i = 1; i <= n; i ++) cnt[s[i] - 'a' + 1] ++;
		for(int i = 1; i <= 26; i ++) if(cnt[i]) {
			if(cnt[i] < k) {
				putchar(s[k]); goto nxt;
			} else {
				cnt[i] -= k; int last = -1;
				for(int j = 26; j >= 1; j --) if(cnt[j]) {
					last = j; break ;
				}
				putchar(i + 'a' - 1);
				if(-1 == last) goto nxt;
				bool fun = 0;
				
				for(int j = i; j < last; j ++) {
					while(cnt[j] --) {
						putchar(j + 'a' - 1); fun = 1;
					}
				}
				int dv = fun ? 1 : k;
				int lim = (cnt[last] + dv - 1) / dv;
				for(int x = 1; x <= lim; x ++) putchar(last + 'a' - 1);
				goto nxt;
			}
			break ;
		}
		nxt:
		puts("");
	}	
	return 0;
}