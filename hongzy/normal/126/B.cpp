#include <cstring>
#include <cstdio>

char * No_res = "Just a legend\n";

char s[1000100];
int n, f[1000100];

void get_fail() {
	f[0] = f[1] = 0;
	for(int i = 1; i < n; i ++) {
		int j = f[i];
		for(; j && s[i] != s[j]; j = f[j]) ;
		f[i + 1] = s[i] == s[j] ? ++ j : 0;
	}
}

bool KMP(char * T, int len) {
	int j = 0;
	for(int i = 1; i < n-1; i ++) {
		for(; j && T[j] != s[i]; j = f[j]) ;
		if(T[j] == s[i]) ++ j;
		if(len == j) return true;
	}
	return false;
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	get_fail();
	for(int k = f[n]; k; k = f[k])
		if(KMP(s, k)) return printf("%s\n", &s[n-k]), 0;
	printf(No_res);
	return 0;
}