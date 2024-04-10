#include <cstdio>

int n, ans[10010];
char s[110], t[113];
int cnt1[511], cnt2[501];

int main() {
	scanf("%d\n%s\n%s", &n, s, t);
	for(int i=0; i<n; i++) {
		cnt1[ s[i] ] ++;
		cnt2[ t[i] ] ++;
	}
	for(int i='a'; i<='z'; i++)
		if(cnt1[i] != cnt2[i]) return puts("-1"), 0;
	int tmp;
	for(int i=0; i<n; i++) {
		if(s[i] != t[i]) {
			int j;
			for(j=i+1; j!=n; j++)
				if(t[i] == s[j]) break;
			if(t[i] != s[j]) return puts("error"), 0;
			for(; j>i; j--) {
				tmp=s[j], s[j]=s[j-1], s[j-1]=tmp, ans[++ ans[0]] = j;
				if(ans[0] > 1e4) return puts("-1"), 0;
			}
		}
	}
	printf("%d\n", ans[0]);
	for(int i=1; i<=ans[0]; i++)
		printf("%d%c", ans[i], " \n"[i == ans[0]]);
	return 0;
}
/*
6
abcdef
abdfec

6
abcdef
abdfec

*/