#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 110;

int n, a[N], cnt[N], b[N];
char s[N][N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	while(1) {
		int pos = -1;
		for(int i = 1; i <= n; i ++) {
			if(a[i] == cnt[i]) {
				pos = i; break ;
			}
		}
		if(pos == -1) break ;
		b[pos] = 1;
		for(int i = 1; i <= n; i ++) if(s[pos][i] == '1') {
			cnt[i] ++;
		}
	}
	int res = 0;
	for(int i = 1; i <= n; i ++) res += b[i];
	printf("%d\n", res);
	for(int i = 1; i <= n; i ++)
		if(b[i]) printf("%d ", i); 
	return 0;
}